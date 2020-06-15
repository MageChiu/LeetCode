/*
 * =====================================================================================
 *
 *       Filename:  mychiu.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年12月17日 19时51分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Charles Chiu (), charles.r.chiu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "mychiu.h"
#include <time.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ChiuTime::print_time()
{
    _cur_time = clock();
    std::cout << (_cur_time - _pre_time) / static_cast<double>(CLOCKS_PER_SEC) << std::endl;
    _pre_time = _cur_time;
    return 0;
}

static int print_tree(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    print_tree(root->left);
    std::cout << root->val << std::endl;
    print_tree(root->right);
    return 0;
}

TreeNode *ChiuTool::creat_tree(std::vector<std::string> indata)
{
    std::queue<TreeNode *> tq;
    std::string str = indata[0];
    int number;
    std::stringstream ss;
    ss << str;
    ss >> number;
    TreeNode *root = new TreeNode(number);
    tq.push(root);
    int pos = 1;
    int i = pos;
    TreeNode *tmpPtr = NULL;
    std::cout << indata.size() << std::endl;
    while (i < indata.size())
    {
        std::cout << i << std::endl;
        tmpPtr = tq.front();
        tq.pop();
        if (tmpPtr == NULL)
        {
            continue;
        }
        if (strcmp(indata[i].c_str(), "null") == 0)
        {
            tmpPtr->left = NULL;
        }
        else
        {
            ss.clear();
            ss << indata[i];
            ss >> number;
            tmpPtr->left = new TreeNode(number);
        }
        tq.push(tmpPtr->left);
        i++;
        if (i == indata.size())
        {
            break;
        }
        if (strcmp(indata[i].c_str(), "null") == 0)
        {
            tmpPtr->right = NULL;
        }
        else
        {
            ss.clear();
            ss << indata[i];
            ss >> number;
            tmpPtr->right = new TreeNode(number);
        }
        tq.push(tmpPtr->right);
        i++;
    }
    return root;
}

ListNode *ChiuTool::create_list(std::vector<int> nums)
{
    if (nums.size() <= 0)
    {
        return nullptr;
    }
    ListNode list_header(0);
    ListNode *tmp_ptr = &list_header;
    for (int i = 0; i < nums.size(); i++)
    {
        tmp_ptr->next = new ListNode(nums[i]);
        tmp_ptr = tmp_ptr->next;
    }
    return list_header.next;
}

template <typename T>
void Common::print_data(const std::vector<T> &data)
{
    std::cout << "[";
    for (int i = 0; i < data.size(); i++)
    {
        if (i == data.size() - 1)
        {
            std::cout << data[i];
        }
        else
        {
            std::cout << data[i] << " , ";
        }
    }
    std::cout << " ]" << std::endl;
}

template <typename T>
void Common::print_data(T data)
{
    std::cout << "[" << data << "]" << std::endl;
}

void Common::print_data(TreeNode *root)
{
    std::cout << "print tree node " << std::endl;
    std::cout << "===============================" << std::endl;
    printInorder(root, 0,"H",17);
    std::cout << "===============================" << std::endl;
}

void printInorder(TreeNode *root, int height, std::string to, int len)
{
    if (NULL == root)
        return;
    printInorder(root->right, height + 1, "v", len); //先打印右子树
    //打印跟节点
    std::stringstream ss;
    ss << root->val;
    std::string val = to + ss.str() + to; //构造H*H或v*v或^*^
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = std::string(lenL, ' ') + val + std::string(lenR, ' ');
    std::cout << std::string(height * len, ' ') << val << std::endl;
    printInorder(root->left, height + 1, "^", len);
    return;
}

template <typename T>
bool Common::check_vector_equal(const std::vector<T> &v1, const std::vector<T> &v2)
{
    size_t l1 = v1.size();
    size_t l2 = v2.size();
    if (l1 != l2)
    {
        std::cout << "[ len not equal ]" << std::endl;
        return false;
    }
    bool flag = true;
    for (size_t ui = 0; ui < l1; ui++)
    {
        if (v1[ui] != v2[ui])
        {
            std::cout << "v1[" << v1[ui] << "] and v2[" << v2[ui] << "] at [" << ui << "] not equal" << std::endl;
            flag = false;
        }
    }
    return flag;
}

int _utest()
{
    std::vector<std::string> test_str = {"1", "null", "3", "2"};
    ChiuTool ct;
    TreeNode *test_root = ct.creat_tree(test_str);
    print_tree(test_root);
    return 0;
}

int _utest_common()
{
    std::vector<int> test = {1, 2, 3, 4, 5};
    Common::print_data(test);

    int k = 12;
    Common::print_data(k);

    std::vector<bool> test_bool = {true};

    Common::print_data(test_bool);
}

#ifdef CHIUTOOL

int main(int argc, char const *argv[])
{
    _utest_common();
    return 0;
}

#endif
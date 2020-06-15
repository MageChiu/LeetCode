/*****************************************************
* 	 Filename: 	 LeetCode297_SerializeandDeserializeBinaryTree.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 297. Serialize and Deserialize Binary Tree	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-16T00:16:09.997Z+08:00
* 	 Modified: 	 2020-06-16T00:16:09.997Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include "mychiu.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        ss << "[";
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp == NULL) {
                ss << "null";
            } else {
                ss << tmp->val;
                q.push(tmp->left);
                q.push(tmp->right);
            }
            if (!q.empty()) {
                ss << ",";
            }
        }
        ss << "]";
        ss >> ret;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() <= 2) {
            return NULL;
        }
        string d = data.substr(1, data.size() - 2);
        vector<string> ss = split(d, ',');
        return deserializeFromStrs(ss);
    }
private:
    TreeNode* deserializeFromStrs(const vector<string> &strs) {
        if (strs.empty() || strs[0] == "null") {
            return NULL;
        }
        TreeNode *root = new TreeNode(std::stoi(strs[0], nullptr));
        queue<TreeNode*> t;
        t.push(root);
        int i = 1;
        while(i < strs.size()) {
            TreeNode* tmp = t.front();
            t.pop();
            if (strs[i] != "null") {
                tmp->left = new TreeNode(std::stoi(strs[i]));
                t.push(tmp->left);
            }
            i++;
            if (strs[i] != "null") {
                tmp->right = new TreeNode(std::stoi(strs[i]));
                t.push(tmp->right);
            }
            i++;
        }
        return root;
    }
    vector<string> split(const string &str, const char pattern) {
        vector<string> res;
        stringstream input(str);   //读取str到字符串流中
        string temp;
        while(getline(input, temp, pattern))
        {
            res.push_back(temp);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main(int argc, char const *argv[])
{
    /* code */
    string test_data = "[1,2,3,null,null,4,5]";
    Codec tester;
    TreeNode* rt = tester.deserialize(test_data);
    Common::print_data(rt);
    string ret_str = tester.serialize(rt);
    cout << ret_str << endl;
    cout << "-----------------------" << endl;
    // rt = tester.deserialize(ret_str);
    // Common::print_data(rt);
    // cout << rt->left->left->val << endl;
    return 0;
}


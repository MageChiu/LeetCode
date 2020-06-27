/*****************************************************
* 	 Filename: 	 LeetCode124_BinaryTreeMaximumPathSum.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	124. Binary Tree Maximum Path Sum 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-21T16:46:50.548Z+08:00
* 	 Modified: 	 2020-06-21T16:46:50.548Z+08:00
* 	 Compiler: 	 g++
*****************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "mychiu.h"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        vector<int> tmp = maxPathSumDetail(root);
        return tmp[0];
    }
    vector<int> maxPathSumDetail(TreeNode* root) {
        int max_tmp = 0;    // 当前子树能够提供的最大的值
        int max_with_root;  // 当前以跟节点的为终点的最大值
        if (root == NULL) {
            return vector<int> {0, 0};
        }
        int root_val = root->val;
        max_with_root = root_val;
        vector<int> l_detail;
        vector<int> r_detail;
        max_tmp = root_val;
        if (root->left != NULL) {
            l_detail = maxPathSumDetail(root->left);
            max_with_root = max(max_with_root, root_val + l_detail[1]);
            max_tmp = max(max_tmp, max_tmp + l_detail[1]);
        }
        if (root->right != NULL) {
            r_detail = maxPathSumDetail(root->right);
            max_with_root = max(max_with_root, root_val + r_detail[1]);
            max_tmp = max(max_tmp, max_tmp + r_detail[1]);
        }
        
        if (root->left != NULL) {
            max_tmp = max(l_detail[0], max_tmp);
            max_tmp = max(l_detail[1], max_tmp);
        }
        if (root->right != NULL) {
            max_tmp = max(r_detail[0], max_tmp);
            max_tmp = max(r_detail[1], max_tmp);
        }
        printf("node[%d], max_tme[%d], with_root[%d]\n", root->val, max_tmp, max_with_root);
        return vector<int>{max_tmp, max_with_root};
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    Solution so;
    cout << so.maxPathSum(root) << endl;
    return 0;
}



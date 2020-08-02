/*
 * @Author: zhaopeng 
 * @Date: 2020-08-02 22:53:55 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-08-02 23:39:01
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_data(TreeNode* test) {
    if (test == NULL) {
        cout << "\tnull" ;
        return;
    }
    cout << "\t" << test->val;
    print_data(test->left);
    print_data(test->right);
}

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        stack<TreeNode*> data;
        if (root->right != NULL) {
            data.push(root->right);
            root->right = NULL;
        }
        if (root->left != NULL) {
            data.push(root->left);
            root->left = NULL;
        }
        TreeNode* head = root;
        head->left = NULL;
        head->right = NULL;
        
        int i = 0;
        cout << i << endl;
        while (!data.empty())
        {
            /* code */
            cout << i++ << endl;
            TreeNode* tmp = data.top();
            data.pop();
            if(tmp->right!= NULL) {
                data.push(tmp->right);
                tmp->right = NULL;
            }
            if (tmp->left != NULL) {
                data.push(tmp->left);
                tmp->left = NULL;
            }
            head->left = NULL;
            head->right = tmp;
            head = head->right;
            if (root->left != NULL) {
                cout << "ee" << endl;
            }
        }
        cout << "====" << endl;
        print_data(root);   
    }
};





int main(int argc, char const *argv[])
{
    /* code */
    TreeNode* test = new TreeNode(1);
    test->left = new TreeNode(2);
    test->right = new TreeNode(3);

    Solution so;
    so.flatten(test);
    print_data(test);
    cout << endl;
    return 0;
}


#include "mychiu.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        queue<TreeNode*> ltmp;
        queue<TreeNode*> rtmp;
        if (root->left != NULL) {
            ltmp.push(root->left);
        }
        if (root->right != NULL) {
            rtmp.push(root->right);
        } 
        while(!ltmp.empty() || !rtmp.empty()) {
            if (ltmp.size() != rtmp.size()) {
                return false;
            }
            TreeNode* lt = ltmp.front();
            ltmp.pop();
            TreeNode* rt = rtmp.front();
            rtmp.pop();
            if (lt == NULL) {
                if (rt != NULL) {
                    return false;
                } else {
                    continue;
                }
            } else {
                if (rt == NULL) {
                    return false;
                } else {
                    if (lt->val != rt->val) {
                        return false;
                    }
                }
            }
            ltmp.push(lt->left);
            ltmp.push(lt->right);
            rtmp.push(rt->right);
            rtmp.push(rt->left);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution so;
    cout << so.isSymmetric(root) << endl;
    return 0;
}

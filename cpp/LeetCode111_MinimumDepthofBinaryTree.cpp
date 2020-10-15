#include "mychiu.h"

using namespace std;

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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } 
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int l = 5000;
        int r = 5000;
        if (root->left != NULL) {
            l = minDepth(root->left);
        }
        if (root->right != NULL) {
            r = minDepth(root->right);
        }
        return (l < r ? l : r) + 1;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

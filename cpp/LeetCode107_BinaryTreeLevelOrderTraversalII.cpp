#include <vector>
#include <queue>
#include <algorithm>
#include "mychiu.h"

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) {
            return ret;
        }
        int f = 0;
        queue<TreeNode*> d[2];
        d[f].push(root);
        while(!d[f].empty()) {
            vector<int> t;
            t.reserve(d[f].size());
            while(!d[f].empty()) {
                t.push_back(d[f].front()->val);
                if (d[f].front()->left != NULL) {
                    d[!f].push(d[f].front()->left);
                }
                if (d[f].front()->right != NULL) {
                    d[!f].push(d[f].front()->right);
                }
                d[f].pop();
            }
            ret.push_back(t);
            f = !f;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

/*
 * @Author: zhaopeng 
 * @Date: 2020-07-21 00:42:07 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-07-21 01:02:15
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

#include <vector>
#include <iostream>
// #include "mychiu.h"

using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return vector<TreeNode*> {};
        }
        return generateTreesByList(1, n);
    }
    vector<TreeNode*> generateTreesByList(int s, int e) {
        vector<TreeNode*> data;
        if (s == e) {
            data.push_back(new TreeNode(s));
            return data;
        } else if (s > e) {
            data.push_back(NULL);
            return data;
        } else {
            /* code */
            for (int i = s; i <= e; i++) {
                int x = i;
                vector<TreeNode*> left_list = generateTreesByList(s, i-1);
                vector<TreeNode*> right_list = generateTreesByList(i+1, e);
                for (int j = 0; j< left_list.size(); j++) {
                    for (int k = 0; k < right_list.size(); k++) {
                        if (left_list[j] == right_list[k]) {
                            // left == null
                            // right == null
                            continue;
                        }
                        data.push_back(new TreeNode(i, left_list[j], right_list[k]));
                    }
                }
            }
            return data;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    int n =3;
    Solution so;
    vector<TreeNode*> ret = so.generateTrees(n);
    // Common::print_data(ret);
    cout << ret.size() << endl;
    cout << ret[0]->val << endl;
    return 0;
}



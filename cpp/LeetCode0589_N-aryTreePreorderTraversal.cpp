/*****************************************************
* 	 Filename: 	 LeetCode0589_N-aryTreePreorderTraversal.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 589. N-ary Tree Preorder Traversal	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-10T23:26:34.619Z+08:00
* 	 Modified: 	 2020-06-10T23:26:34.619Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> data;
        stack<Node*> n;
        n.push(root);
        while(!n.empty()) {
            Node* tmp = n.top();
            n.pop();
            if (tmp == NULL) {
                continue;
            }
            data.push_back(tmp->val);
            for (int i = tmp->children.size()-1; i>=0; i--) {
                n.push(tmp->children[i]);
            }
        }
        return data;
    }
};


int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    Solution so;
    vector<int> res = so.preorder(root);
    for (int i = 0; i< res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}

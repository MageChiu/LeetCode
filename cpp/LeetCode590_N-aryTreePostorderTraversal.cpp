/*****************************************************
* 	 Filename: 	 LeetCode590_N-aryTreePostorderTraversal.cpp
* 	 Author: 	 zhaopeng
* 	 Description:590. N-ary Tree Postorder Traversal 	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-10T23:02:30.529Z+08:00
* 	 Modified: 	 2020-06-10T23:02:30.529Z+08:00
* 	 Compiler: 	 g++
*****************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    vector<int> postorder(Node* root) {
        stack<Node*> tmp;
        tmp.push(root);
        stack<int> data;
        while(!tmp.empty()) {
            Node* t = tmp.top();
            tmp.pop();
            if (t == NULL) {
                continue;
            }
            data.push(t->val);
            for (int i = 0; i < t->children.size(); i++) {
                tmp.push(t->children[i]);
            }
        }
        vector<int> res;
        res.reserve(data.size());
        while(!data.empty()) {
            res.push_back(data.top());
            data.pop();
        }
        return res;
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
    vector<int> res = so.postorder(root);
    for (int i = 0; i< res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}



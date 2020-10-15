#include <queue>
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        queue<Node*> d[2];
        int f = 0;
        d[f].push(root);
        while(!d[f].empty()) {
            Node* tmp = d[f].front();
            d[f].pop();
            if (tmp->left != NULL) {
                d[!f].push(tmp->left);
            }
            if (tmp->right != NULL) {
                d[!f].push(tmp->right);
            }
            while(!d[f].empty()) {
                tmp->next = d[f].front();
                tmp = d[f].front();
                d[f].pop();
                if (tmp->left != NULL) {
                    d[!f].push(tmp->left);
                }
                if (tmp->right != NULL) {
                    d[!f].push(tmp->right);
                }
            }
            tmp->next = NULL;
            f = !f;
        }
        return root;
    }
};
#include "mychiu.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* next = head->next;
        if (next == NULL) {
            return head;
        }
        ListNode* tmp = next->next;
        next->next = head;
        head->next = swapPairs(tmp);
        return next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


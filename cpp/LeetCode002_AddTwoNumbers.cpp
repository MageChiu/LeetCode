/*
 * @Author: charles 
 * @Date: 2019-11-04 02:13:33 
 * @Last Modified by: charles
 * @Last Modified time: 2019-11-04 02:29:06
 */

#include "leetcode_header.h"
#include "mychiu.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL;
        ret = addTwoPoint(l1, l2, 0);
        return ret;
    }
    ListNode *addTwoPoint(ListNode *l1, ListNode *l2, int carry)
    {
        if (l1 == NULL && l2 == NULL)
        {
            if (carry == 0)
                return NULL;
            else {
                ListNode *npoint = new ListNode(carry);
                return npoint;
            }
        }
        else if (l1 == NULL && l2 != NULL)
        {
            int tmp = l2->val + carry;
            ListNode *npoint = new ListNode(tmp % 10);
            npoint->next = addTwoPoint(l1, l2->next, tmp / 10);
            return npoint;
        }
        else if (l1 != NULL && l2 == NULL)
        {
            int tmp = l1->val + carry;
            ListNode *npoint = new ListNode(tmp % 10);
            npoint->next = addTwoPoint(l1->next, l2, tmp / 10);
            return npoint;
        }
        else
        {
            int tmp = l1->val + l2->val + carry;
            ListNode *npoint = new ListNode(tmp % 10);
            npoint->next = addTwoPoint(l1->next, l2->next, tmp / 10);
            return npoint;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    ChiuTool chiu_tool;
    vector<int> test_num_1 = {1, 2, 3};
    vector<int> test_num_2 = {1, 2, 3};
    ListNode* l_1 = chiu_tool.create_list(test_num_1);
    ListNode* l_2 = chiu_tool.create_list(test_num_2);
    Solution so;
    ListNode* ret_ptr = so.addTwoNumbers(l_1, l_2);
    ListNode* tmp_ptr = ret_ptr;
    while(tmp_ptr != nullptr) {
        cout << tmp_ptr->val << endl;
        tmp_ptr = tmp_ptr->next;
    }
    return 0;
}



/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned sum = 0;
        ListNode* current = new ListNode(0);
        ListNode* solution = current;

        while(l1 or l2)
        {

            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;  

            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            current->next = new ListNode(sum%10);
            current = current -> next;
            
            sum = sum>9?1:0;

        }
        
        if(sum)
        {
            current->next = new ListNode(sum);
        }
        
        return solution->next;
    }
};
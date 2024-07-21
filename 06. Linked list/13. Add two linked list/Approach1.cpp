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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            int node_val = sum%10;
            carry = sum/10;
            ListNode* ptr = new ListNode(node_val);
            temp->next = ptr;
            temp = temp->next;
        }

        while(l1)
        {
            int sum = l1->val +  carry;
            l1 = l1->next;
            int node_val = sum%10;
            carry = sum/10;
            ListNode* ptr = new ListNode(node_val);
            temp->next = ptr;
            temp = temp->next;
        }

        while(l2)
        {
            int sum = l2->val +  carry;
            l2 = l2->next;
            int node_val = sum%10;
            carry = sum/10;
            ListNode* ptr = new ListNode(node_val);
            temp->next = ptr;
            temp = temp->next;
        }

        if(carry!=0)
        {
            ListNode* ptr = new ListNode(carry);
            carry = 0;
            temp->next = ptr;
            temp = temp->next;
        }
        return dummy->next;
    }
};

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
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)  return head;

        ListNode* ptr = head;
        ListNode* prev = NULL;
        while(ptr!=NULL)
        {
            ListNode* next_ptr = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next_ptr;
        }

        return prev;
    }
    ListNode* addList(ListNode* l1,ListNode* l2)
    {
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
            ListNode* node = new ListNode(node_val);
            temp->next = node;
            temp = temp->next;
        }

        while(l1)
        {
            int sum = l1->val + carry;
            l1 = l1->next;
            int node_val = sum%10;
            carry = sum/10;
            ListNode* node = new ListNode(node_val);
            temp->next = node;
            temp = temp->next;
        }

        while(l2)
        {
            int sum = l2->val + carry;
            l2 = l2->next;
            int node_val = sum%10;
            carry = sum/10;
            ListNode* node = new ListNode(node_val);
            temp->next = node;
            temp = temp->next;
        }

        if(carry!=0)
        {
            ListNode* node = new ListNode(carry);
            carry = 0;
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* ans = addList(l1,l2);
        ans = reverseList(ans);
        return ans;
    }
};

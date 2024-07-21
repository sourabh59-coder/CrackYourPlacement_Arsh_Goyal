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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;


        ListNode* dummy = new ListNode(-130);
        dummy->next = head;
        head = dummy;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next!=NULL)
        {
            if(curr->val!=next->val)
            {
                prev = curr;
                curr = next;
                next = next->next;
            }
            else
            {
                while(next!=NULL && next->val==curr->val)
                {
                    next = next->next;
                }
                prev->next = next;
                curr = prev->next;
                if(curr!=NULL)  next = curr->next;
                else            next = NULL;
            }
        }

        return dummy->next;
    }
};

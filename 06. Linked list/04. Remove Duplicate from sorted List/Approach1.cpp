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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow!=NULL && fast!=NULL)
        {
            if(fast->val==slow->val)
            {
                slow->next = fast->next;
                fast = fast->next;
                // slow = slow->next;
                // if(slow!=NULL)
                // {
                //     fast = slow->next;
                // }
                // else    break;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return dummy->next;
    }
};

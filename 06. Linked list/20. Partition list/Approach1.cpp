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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        ListNode* dummy2 = new ListNode(-1);
        ListNode* ptr2 = dummy2;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                ptr->next = head;
                ptr = ptr->next;
                head = head->next;
            }
            else
            {
                ptr2->next = head;
                ptr2 = ptr2->next;
                head = head->next;
            }
        }
        ptr2->next = NULL;
        ptr->next = dummy2->next;
        return dummy->next;
    }
};

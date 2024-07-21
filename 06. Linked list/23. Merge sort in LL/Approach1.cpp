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
    ListNode* mergeList(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;

        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }

        if(l1)
        {
            ptr->next = l1;
        }

        if(l2)
        {
            ptr->next = l2;
        }

        return dummy->next;
    }
    ListNode* middle(ListNode* head)
    {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev!=NULL)  prev->next = NULL;

        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* mid = middle(head);
        // if(mid==NULL)   return head;
        // ListNode* l1 = head;
        // ListNode* l2 = mid->next;
        // mid->next = NULL;
        head = sortList(head);
        mid = sortList(mid);
        head = mergeList(head,mid);
        return head;
    }
};

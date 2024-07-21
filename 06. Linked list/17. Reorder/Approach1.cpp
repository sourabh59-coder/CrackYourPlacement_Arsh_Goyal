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
        ListNode* prev = NULL;
        ListNode* ptr = head;

        while(ptr!=NULL)
        {
            ListNode* ptr_next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = ptr_next;
        }

        return prev;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l1 && l2)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;

            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        if(l1)
        {
            temp->next = l1;
        }

        if(l2)
        {
            temp->next = l2;
        }
        return dummy->next;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)    return;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = slow->next;
        slow->next = NULL;
        ListNode* l1 = head;
        l2 = reverseList(l2);

        head = mergeTwoLists(l1,l2);
    }
};

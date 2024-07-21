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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right || right==1)   return head;

        ListNode* dummy = new ListNode(-510);
        dummy->next = head;
        head = dummy;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0;i<left;i++)
        {
            prev = slow;
            slow = slow->next;
        } 
        for(int i=0;i<right;i++)    fast = fast->next;

        ListNode* fast_next = fast->next;
        fast->next = NULL;
        ListNode* temp = reverseList(slow);
        prev->next = temp;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = fast_next;
        return dummy->next;
    }
};

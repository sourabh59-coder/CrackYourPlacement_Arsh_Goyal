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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)    return NULL;

        ListNode* start = lists[0];
        ListNode* second = NULL;
        for(int i=1;i<n;i++)
        {
            second = lists[i];
            start = mergeList(start,second);
        }
        return start;
    }
};

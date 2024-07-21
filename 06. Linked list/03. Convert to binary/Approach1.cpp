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
    int getDecimalValue(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        
        while(temp) {
            temp = temp->next;
            size++;
        }
        
        size--;
        temp = head;
        int res = 0;
        while(temp != NULL && size>=0) {
            res += temp->val*(1<<size);
            temp = temp->next;
            size--;
        }
        return res;
    }
};

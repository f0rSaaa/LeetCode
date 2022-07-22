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
        ListNode *lt = new ListNode(0);
        ListNode *gt = new ListNode(0);
        ListNode *lh = lt,*gh = gt;
        while(head != NULL){
            if(head->val < x){
                lt->next = head;
                head = head->next;
                lt = lt->next;
            } else {
                gt->next = head;
                head = head->next;
                gt = gt->next;
            }
        }
        gt->next = NULL;
        lt->next = gh->next;
        return lh->next;
    }
};
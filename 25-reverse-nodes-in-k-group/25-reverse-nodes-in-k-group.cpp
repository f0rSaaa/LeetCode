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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int n = 0;
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            n++;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy, *curr = dummy, *nex = dummy;
        while(n>=k){
            curr = pre->next;
            nex = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            n-=k;
        }
        return dummy->next;
    }
};
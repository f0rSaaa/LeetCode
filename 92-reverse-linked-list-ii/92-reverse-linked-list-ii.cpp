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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummy = new ListNode(0);
        dummy->next = head;
        ListNode *leftprev = dummy, *curr = head;
        // while(curr->val != left){
        //     leftprev = curr;
        //     curr = curr->next;
        //     // head = head->next;
        // }
        for(int i=1;i<left;++i){
            leftprev = curr;
            curr = curr->next;    
        }
        ListNode *newH = NULL;
        for(int i=1;i<=(right-left+1);++i){
            ListNode *nex = curr->next;
            curr->next = newH;
            newH = curr;
            curr = nex;
        }
        
        leftprev->next->next = curr;
        leftprev->next = newH;
        return dummy->next;
    }
};
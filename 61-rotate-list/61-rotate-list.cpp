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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL|| head->next == NULL || k == 0)
            return head;
        int len =1;
        ListNode* curr = head;
        while(curr->next != NULL){
            len++;
            curr = curr->next;
        }
        curr->next = head;  // joining the last and the first node
        k = k % len;    // since k can be greater than the size of the linked list
        k = len - k;
        //move the curr pointer from the last node to where the list should be rotated
        while(k--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};
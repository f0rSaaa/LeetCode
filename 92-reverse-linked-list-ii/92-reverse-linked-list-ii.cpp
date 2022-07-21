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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *leftprev = dummy, *cur = head;;
        
        for(int i =1;i<left;i++){
            leftprev = cur;
            cur = cur->next;
        }
        cout << cur->val << " ";
        ListNode *newH = NULL;
        for(int i=1;i<= (right-left+1);i++){
            ListNode * nex = cur->next;
            cur->next = newH;
            newH = cur;
            cur = nex;
        }
        cout << leftprev->val << " ";
        cout << leftprev->next->val;
        leftprev->next->next = cur;
        leftprev->next = newH;
        
        return dummy->next;
    }
};
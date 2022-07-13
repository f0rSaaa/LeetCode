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
    
    ListNode * reverseLL(ListNode* head){
        ListNode *newH = NULL;
        while(head != NULL){
            ListNode *next = head->next;
            head->next = newH;
            newH = head;
            head = next;
        }
        return newH;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return false;
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseLL(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
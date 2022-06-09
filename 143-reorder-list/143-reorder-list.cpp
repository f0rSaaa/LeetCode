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
    
    ListNode* reverseLL(ListNode * head){
        ListNode *newH = NULL;
            while(head != NULL){
                ListNode * nex = head->next;
                head->next = newH;
                newH = head;
                head = nex;
                
            }
        return newH;
    }
    
    void merge2LL(ListNode* l1, ListNode* l2) {
      while(l1 != NULL) {
        ListNode* n1 = l1->next, *n2 = l2->next;
        l1->next = l2;
        
        if (n1 == NULL)
          break;
            
        l2->next = n1;
        l1 = n1;
        l2 = n2;
      }
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return ;

        ListNode *slow = head, *fast = head, *temp;
        while(fast != NULL  && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        ListNode *head2 = reverseLL(slow);
        
        merge2LL(head, head2);
        
    }
};
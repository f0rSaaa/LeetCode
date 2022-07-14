/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if(head == NULL)
        //     return NULL;
        // unordered_map<Node* , Node*>mpp;
        // Node* iter = head;
        // while(iter != NULL){
        //     Node * curr = new Node(iter->val);
        //     mpp[iter] = curr;
        //     iter = iter->next;
        // }
        // iter = head;
        // while(iter != NULL){
        //     mpp[iter]->next = mpp[iter->next];
        //     mpp[iter]->random = mpp[iter->random];
        //     iter=  iter->next;
        // }
        // return mpp[head];
        
        if(head == NULL)
            return NULL;
        Node* iter = head, *front = head;
        //1st step create DC node right after original node
        while(iter != NULL){
            front = iter->next;
            Node* copyNode = new Node(iter->val);
            iter->next =copyNode;
            copyNode->next = front;
            iter = front;
        }
        //2nd step assign random pointer
        iter = head;
        while(iter!= NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        //3rd step recover both Linked list OG and DC
        iter= head;
        Node* dummy = new Node(0);
        dummy->next = iter->next;
        Node * copyPtr = dummy;
        while(iter != NULL){
            front = iter->next->next;
            copyPtr->next = iter->next;
            iter->next = front;
            copyPtr = copyPtr->next;
            iter = front;
        }
        return dummy->next;
        
    }
};
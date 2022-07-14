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
        if(head == NULL)
            return NULL;
        unordered_map<Node* , Node*>mpp;
        Node* iter = head;
        while(iter != NULL){
            Node * curr = new Node(iter->val);
            mpp[iter] = curr;
            iter = iter->next;
        }
        iter = head;
        while(iter != NULL){
            mpp[iter]->next = mpp[iter->next];
            mpp[iter]->random = mpp[iter->random];
            iter=  iter->next;
        }
        return mpp[head];
    }
};
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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        vector<int> list;
        ListNode* ptr = head;
        while(ptr){
            list.push_back(ptr->val);
            ptr = ptr->next;
        }
        swap(list[k - 1], list[list.size() - k]);
        head = NULL;
        ptr = NULL;
        for(int i = 0; i < list.size(); i++)
        {
            ListNode *new_node = new ListNode(list[i]);
            if(head == NULL)
            {
                head = new_node;
                ptr = head;
            }
            else
            {
                ptr->next = new_node;
                ptr = ptr->next;
            }
        }
        return head;
    }
};
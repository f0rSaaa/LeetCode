struct Compare {
    bool operator()(ListNode* const& p1, ListNode* const& p2)
    {
        return p1->val > p2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
                if(lists.size() == 0)
            return NULL;
        priority_queue<ListNode* , vector<ListNode*>, Compare>minH;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                minH.push(lists[i]);
        }
//         for(auto it:lists){
            
//         }
   
        if(minH.empty())
            return NULL;
        
        ListNode* ans = minH.top();
        minH.pop();
        if(ans->next != NULL)
            minH.push(ans->next);
        
        ListNode *tail = ans;
        while(minH.empty() == false){
            tail->next = minH.top();
            minH.pop();
            tail = tail->next;
            if(tail->next != NULL)
                minH.push(tail->next);
        }
   
        return ans;
        
    }
};
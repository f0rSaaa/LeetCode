class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxH;
        for(auto it:stones){
            maxH.push(it);
        }
        while(!maxH.empty()){
            if(maxH.size() == 1)
                break;
            int top = maxH.top();
            maxH.pop();
            int top2 = maxH.top();
            maxH.pop();
            int newT = top -top2;
            maxH.push(newT);
        }
        return maxH.top();
  
    }
};
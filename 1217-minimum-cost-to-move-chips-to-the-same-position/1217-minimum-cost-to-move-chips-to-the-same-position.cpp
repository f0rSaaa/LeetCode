class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int>count(2);
        for(auto it:position){
            if(it %2 ==0)
                count[0]++;
            else 
                count[1]++;
        }
        return min(count[0],count[1]);
    }
};
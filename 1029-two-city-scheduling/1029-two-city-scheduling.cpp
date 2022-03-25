class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int acost = 0;
        vector<int>bcost;
        for(int i=0;i<costs.size();i++){
            acost += costs[i][0];
            bcost.push_back(costs[i][1]-costs[i][0]);
        }
        // cout << acost;
        // for(auto it:bcost){
        //     cout << it << " ";
        // }
        sort(bcost.begin(),bcost.end());
        // for(auto it:bcost){
        //     cout << it << " ";
        // }
        int n=costs.size()/2;
        for(int i=0;i<n;i++){
            acost+=bcost[i];
        }
        return acost;
    }
};
class Solution {
public:
    int t[1001];
    int solve(vector<int>&cost, int n){
        // if(n<0)
        //     return 0;
        if(n<=1)
            return cost[n];
        if(t[n] != -1){
            return t[n];
        }
        int a = solve(cost, n-1);
        int b = solve(cost, n-2);
        
        return t[n] = cost[n]+min(a,b);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        return min(solve(cost, cost.size()-1),solve(cost,cost.size()-2));
    }
};
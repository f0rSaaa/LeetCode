class Solution {
public:
    
    int solve(int ind, int buy, vector<int>&prices, int n,vector<vector<int>>&dp){
        if(ind >= n)
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        if(buy == 1){
            return dp[ind][buy] = max(-prices[ind]+solve(ind+1,0,prices, n,dp), 0+ solve(ind+1,1,prices, n,dp));
        } else {
            return dp[ind][buy] = max(prices[ind]+solve(ind+2, 1, prices, n,dp), 0+solve(ind+1,0,prices, n,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
	    return solve(0,1,prices, prices.size(),dp);
    }
};
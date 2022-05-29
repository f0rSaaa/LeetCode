class Solution {
public:
    
    int solve(int i, int j, vector<int>&c,vector<vector<int>>&dp){
        if(i > j)
            return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int mini = INT_MAX;
        for(int k =i;k<=j;k++){
            int cuts = (c[j+1] - c[i-1]) + solve(i,k-1,c,dp) + solve(k+1,j,c,dp);
            if(mini > cuts)
                mini = cuts;
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
    	int x = cuts.size();
        vector<vector<int>>dp(x, vector<int>(x+1,-1));
    	return solve(1,x-2,cuts,dp);
    //     for(int i=c;i>=1;i--){
    //         for(int j=1;j<=c;j++){
    //             if(i>j)
    //                 continue;
    //             int mini = INT_MAX;
    //             for(int k =i;k<=j;k++){
    //                 int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
    // // 				if(mini > cost)
    // // 					mini = cost;
    //                 mini = min(mini, cost);
    //             }
    //             dp[i][j] = mini;
    //         }
    //     }
    //     return dp[1][c];
    }
};
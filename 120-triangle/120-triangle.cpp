class Solution {
public:
    
    
    int solve(int i, int j, vector<vector<int>>&t, int n,vector<vector<int>>&dp){
        if(i == n-1)
            return t[n-1][j];
        if(i>=n)
            return INT_MAX;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i+1,j,t,n,dp);
        int diag = solve(i+1, j+1, t, n,dp);

        return dp[i][j] = t[i][j] + min(down, diag);
    }

    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
	    return solve(0,0,triangle, n,dp);
    }
};
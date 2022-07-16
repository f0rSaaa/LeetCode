class Solution {
public:
    int mod = 1e9+7;
    vector<pair<int, int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}};

    int dfs(int i, int j, int m, int n, int MM, vector<vector<vector<int>>>&dp){
        if(i<0 || j<0 || i>=m || j >= n)
            return 1;
        if(MM == 0)
            return 0;
        if(dp[i][j][MM] != -1)
            return dp[i][j][MM];
        int res = 0;
        for(auto it:dirs){
            int ni = it.first + i;
            int nj = it.second + j;
            res = (res+dfs(ni,nj,m,n,MM-1,dp)%mod) % mod;
            dp[i][j][MM] = res;
        }
        return dp[i][j][MM];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn,m,n,maxMove,dp);        
    }
};
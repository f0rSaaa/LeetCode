class Solution {
public:
    vector<pair<int, int>>d = {{1,0},{0,1},{-1,0},{0,-1}};
    int mod = 1e9+7;
    long long dfs(vector<vector<int >>&grid, int i, int j, int n, int m,vector<vector<int>>&dp){
        
        if(dp[i][j]!=-1) return dp[i][j];
        long long tempres = 0;
        // for(auto [x,y]: d){
        //     x+=i;
        //     y+=j;
        //     if(x <0 || y < 0 || x >=n || y >=m || grid[x][y] <= grid[i][j]) continue;
        //     tempres = (1 + tempres+dfs(grid,x,y,n,m,dp)) % mod;
        // }
        for(auto it:d){
            int x = i + it.first;
            int y = j + it.second;
            if(x <0 || y < 0 || x >= n || y >= m || grid[x][y] <= grid[i][j])
                continue;
            tempres = (1 + tempres + dfs(grid, x, y, n, m, dp)) % mod;
        }
        return dp[i][j] = tempres%mod;
    }
    
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        long long  res = 0;        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    res = (res + 1+ dfs(grid,i,j,n,m,dp)) % mod;

            }
        }
        return res%mod;
    }
};
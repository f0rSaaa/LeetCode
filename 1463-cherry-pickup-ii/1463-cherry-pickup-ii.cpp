class Solution {
public:
    
    int solve(int i, int j1, int j2, int c, int r, vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(j1<0 || j2 < 0 || j1 >=c || j2 >=c)
            return -1e8;
        if(i == r-1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = -1e8;
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        for(int dj1 = -1;dj1<2;dj1++){
            for(int dj2 = -1;dj2<2;dj2++){
                if(j1 == j2){
                    int temp = grid[i][j1] + solve(i+1,j1+dj1,j2+dj2,c,r,grid,dp);
                    maxi = max(maxi, temp);
                } else {
                    int temp = grid[i][j1] +grid[i][j2]+ solve(i+1,j1+dj1,j2+dj2,c,r,grid,dp);
                    maxi = max(maxi, temp);
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return solve(0,0,c-1,c,r,grid,dp);
    }
};
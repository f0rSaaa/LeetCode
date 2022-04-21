class Solution {
public:
    //https://leetcode.com/problems/unique-paths-ii/discuss/1180249/Easy-Solutions-w-Explanation-and-Comments-or-Optimization-from-Brute-Force-Approach
    
    int solve(int i, int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
        if( i==0 && j==0)
            return 1;

        if(i < 0 || j < 0)
            return 0;

        if(mat[i][j] == 1)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int left = solve(i,j-1,mat,dp);
        int top = solve(i-1,j,mat,dp);

        return dp[i][j] = left+top;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1)
            return 0;
        if(n == 1){
            vector<int>temp(obstacleGrid[0].begin(),obstacleGrid[0].end());
            int sum = accumulate(temp.begin(),temp.end(),0);
            if(sum >=1)
                return 0;
            else
                return 1;
        }

        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};
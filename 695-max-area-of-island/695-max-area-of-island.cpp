class Solution {
public:
    vector<pair<int, int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0)
            return 0;
        int tempres =1;
        grid[i][j] = 0;
        for(auto it:dirs){
            int x = it.first+i;
            int y = it.second+j;
            tempres+=dfs(grid,x,y,n,m);
        }
        return tempres;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    res = max(res, dfs(grid, i,j,n,m));
            }
        }
        return res == INT_MIN? 0: res;
    }
};
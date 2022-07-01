class Solution {
public:
    // vector<pair<int, int>>d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<pair<int, int>>d = {{1,0},{0,1},{1,0},{0,-1}};
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int i, int j, int n, int m){
        if(i <0 || j < 0 || i >=n || j >=m || grid[i][j] == '0')
            return;
        if(vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        // dfs(gird, vis, )
        // for(int k=0;i<4;i++){
        //     int x = i+d[k].first;
        //     int y = j+d[k].second;
        //     dfs(grid, vis,i+x,i+y,n,m);
        // }
        dfs(grid, vis, i-1, j, n, m);
        dfs(grid, vis, i+1, j, n, m);
        dfs(grid, vis, i, j-1, n, m);
        dfs(grid, vis, i, j+1, n, m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid,vis, i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};
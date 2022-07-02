class Solution {
public:
    
    vector<pair<int, int>>d = {{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i <0 || j < 0 || i >=n || j >=m || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int tempres = 1;
        for(int k=0;k<4;k++){
            int x = i+d[k].first;
            int y = j+d[k].second;
            tempres += dfs(grid,x,y,n,m);
        }
        return tempres;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int  res = 0;        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    res =max(res,dfs(grid,i,j,n,m));

                }
            }
        }
        return res;
    }
};
class Solution {
public:

    vector<pair<int, int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int dfs(vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i<0 || j <0 || i>=n || j>=m || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        
        return 1 + dfs(grid,i-1,j,n,m) + dfs(grid,i,j-1,n,m)+ dfs(grid,i+1,j,n,m) + dfs(grid,i,j+1,n,m);

    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int onec = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    onec++;
            }
        }
        int region1 = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1)
                    region1+=dfs(grid,i,j,n,m);
            }
        }
        return onec-region1;
    }
};
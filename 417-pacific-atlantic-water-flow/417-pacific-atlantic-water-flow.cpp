class Solution {
public:
    
    // void dfs(vector<vector<int>>&mat, vector<vector<bool>>& vis, int i, int j, int n, int m){
    //     vis[i][j] = true;
    //     if(i-1 >= 0 && !vis[i-1][j] && mat[i-1][j] >= mat[i][j]){
    //         dfs(mat,vis,i-1,j,n,m);
    //     }
    //     if(j-1 >= 0 && !vis[i][j-1] && mat[i][j-1] >= mat[i][j]){
    //         dfs(mat,vis,i,j-1,n,m);
    //     }
    //     if(j+1 < n && !vis[j+1][j] && mat[i][j+1] >= mat[i][j]){
    //         dfs(mat,vis,i,j+1,n,m);
    //     }
    //     if(i+1 < m && !vis[i+1][j] && mat[i+1][j] >= mat[i][j]){
    //         dfs(mat,vis,i+1,j,n,m);
    //     }
    // }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        //up
        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));
//         for(int i=0;i<n;i++){
//             dfs(heights, pacific, i,0,n,m);
//             dfs(heights, atlantic, i, m-1,n,m);
//         }
//         for(int j=0;j<m;j++){
//             dfs(heights, pacific, 0,j,n,m);
//             dfs(heights, atlantic, n-1,j,n,m);
//         }
        
        for(int i=0;i<n;i++){
            dfs(heights, pacific, i,0);
            dfs(heights, atlantic, i, m-1);
        }
        for(int j=0;j<m;j++){
            dfs(heights, pacific, 0,j);
            dfs(heights, atlantic, n-1,j);
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }

            }
        }
        return ans;
    }
};
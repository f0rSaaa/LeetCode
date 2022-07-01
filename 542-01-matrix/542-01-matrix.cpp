class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        // vector<pair<int, int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int, int>>qu;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    qu.push({i,j});
                } else 
                    mat[i][j] = -1; // marking the cell as not visited and is yet to be processed
            }
        }
        while(!qu.empty()){
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            for(int i=0;i<4;i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(nx < 0 || ny < 0 || nx >= n || ny >=m || mat[nx][ny] != -1)
                    continue;
                mat[nx][ny] = mat[x][y] + 1;
                qu.push({nx,ny});
            }
        }
        return mat;
    }
};
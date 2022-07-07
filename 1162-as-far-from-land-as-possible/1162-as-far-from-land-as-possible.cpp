class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>>qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    qu.push({i,j});
            }
        }
        vector<pair<int, int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        int dis = 0;
        while(!qu.empty()){
            int size =  qu.size();
            if(size == n*m)
                return -1;
            dis++;
            while(size--){
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();

                for(auto it:dir){
                    int nx = x + it.first;
                    int ny = y + it.second;

                    // if(nx <0 || ny <0 ||nx >=n || ny >=m || grid[nx][ny] == 1)
                    //     continue;
                    if(nx >=0 && ny >=0 && nx <n && ny <m && grid[nx][ny] == 0){
                        qu.push({nx,ny});
                        grid[nx][ny] = grid[x][y] + 1;                   
                    }
                }
            }
        }
        cout << dis ;

        return dis == 0 ?-1 : dis -1;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0)
            return 0;
        int total = 0;
        int rotten = 0;
        int count = 0;
        queue<pair<int, int>>qu;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] != 0)
                    total++;
                if(grid[i][j] == 2){
                    rotten++;
                    qu.push({i,j});
                }
            }
        }
        int days = 0;
        cout << qu.size() << endl;
        vector<pair<int, int>>dirs ={{1,0},{0,1},{-1,0},{0,-1}};
        while(!qu.empty()){
            int size = qu.size();
            count +=size;
            while(size--){
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();
                for(auto it:dirs){
                    int nx = x + it.first;
                    int ny = y + it.second;
                    if(nx < 0 || ny < 0 || nx >=n  || ny >= m || grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    qu.push({nx,ny});
                }
                // days++;
            }
            if(qu.empty())
                break;
            days++;
        }
        cout << count << " " << total << " "<<days;
        return count == total ? days : -1;
    }
};
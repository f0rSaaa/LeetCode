class Solution {
public:
    vector<pair<int, int>>dirs = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    
    bool issafe(int x, int y, int n, int m){
        if(x >=0 && y >=0 && x <n && y <m)
            return true;
        return false;
    }
    
    void dfs(vector<vector<char>>&board, int x, int y){
        int n = board.size();
        int m = board[0].size();
        if(!issafe(x, y, n, m))
            return;
        if(issafe(x,y,n,m) && board[x][y] == 'B')
            return;
        
        int count = 0;
        for(auto it:dirs){
            if(issafe( x+it.first, y+it.second,n,m) && board[x+it.first][y+it.second]=='M')
                count++;
        }
        if(count >0)
            board[x][y] = '0'+count;
        else{
            board[x][y] = 'B';
            for(auto it:dirs){
                dfs(board,x+it.first, y+it.second);
            }
        }
    }
        
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M') {
            board[click[0]][click[1]]='X';
            return board;
        }
        dfs(board, click[0], click[1]);
        return board;
    }
};
class Solution {
public:
    
//     void dfs(vector<vector<char>>&board, int i, int j, int n, int m){
//         board[i][j] = '@';
//         if( i-1>=0 && board[i-1][j] != 'X')
//             dfs(board,i-1,j,n,m);
//         if(j-1 >=0 && board[i][j-1] != 'X')
//             dfs(board,i,j-1,n,m);
//         if(i+1 < n && board[i+1][j] != 'X')
//             dfs(board,i+1,j,n,m);
//         if(j+1 < m && board[i][j+1] != 'X')
//             dfs(board, i,j+1,n,m);
            
//     }
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O') return;
        board[i][j] = '@';
        dfs(board, i-1, j, n, m);
        dfs(board, i+1, j, n, m);
        dfs(board, i, j-1, n, m);
        dfs(board, i, j+1, n, m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n==1)
            return;
        //first and last col
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                dfs(board,i,0,n,m);
            if(board[i][m-1] == 'O')
                dfs(board,i,m-1,n,m);
        }
        //first row and last row
        for(int j=0;j<m;j++){
            if(board[0][j] =='O')
                dfs(board,0,j,n,m);
            if(board[n-1][j] =='O')
                dfs(board,n-1,j,n,m);  
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O')
                    board[i][j] ='X';
                if(board[i][j] == '@')
                    board[i][j] = 'O';
            }
        }
    }
};
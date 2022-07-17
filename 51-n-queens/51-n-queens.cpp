class Solution {
public:
    
    bool isSafe(int row, int col, vector<string> board){
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >=0){ //upper diag
            if(board[row][col] == 'Q')
                return false;
            --row;
            --col;
        } 
        
        col = dupcol;
        row = duprow;
        while(col >=0){
            if(board[row][col] == 'Q')
                return false;
            --col;
        }
        
        col = dupcol;
        row = duprow;
        while(row <board.size() && col >=0){
            if(board[row][col] == 'Q')
                return false;
            ++row;
            --col;
        }
        return true;
    }

    
    void solve(int col, vector<vector<string>>&res, vector<string>&board, int n){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row = 0; row <n ;++row){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                solve(col+1, res, board, n);
                board[row][col] = '.';
            }
        }
    }

    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;   
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,res,board,n);
        return res;
    }
};
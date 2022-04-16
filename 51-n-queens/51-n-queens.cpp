class Solution {
public:
    
    
    bool issafe(int row, int col, vector<string>&board, int n){
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col >=0){   //checking if there is a queen in the topleft direction if there then this position is not safe
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(col>=0){
            //checking if there is a queen in the left direction if there is a queen in the left direction then it is not safe to place a queen there
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(row<n && col >=0){ //checking if there is a queen in the bottom right direction if there is a queen there then it is not safe to place a queen there
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
            
        }
        return true;
    }
    
    void solve(int col, vector<vector<string>>&ans, vector<string>&board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(issafe(row, col,board, n)){
                board[row][col] = 'Q';
                solve(col+1,ans,board, n);
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
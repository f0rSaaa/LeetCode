class Solution {
public:
    
    void solve(int col, vector<vector<string>>&res, vector<string>&board, int n, vector<int>&leftRow, vector<int>&upperDiag, vector<int>&lowerDiag){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row = 0; row<n;row++){
            if(leftRow[row] == 0 && upperDiag[(n-1)+(col-row)] == 0 && lowerDiag[row+col] == 0){
                leftRow[row] = 1;
                upperDiag[(n-1)+(col-row)] = 1;
                lowerDiag[row+col] = 1;
                board[row][col] = 'Q';
                solve(col+1,res,board,n,leftRow, upperDiag,lowerDiag);
                leftRow[row] = 0;
                upperDiag[(n-1)+(col-row)] = 0;
                lowerDiag[row+col] = 0;
                board[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int>leftRow(n,0),upperDiag(2*n-1,0),lowerDiag(2*n-1,0);
        solve(0,res,board,n,leftRow,upperDiag,lowerDiag);
        return res.size();
    }
};
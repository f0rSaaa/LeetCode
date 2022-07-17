class Solution {
public:
    
//     bool isSafe(int row, int col, vector<string> board){
//         int duprow = row;
//         int dupcol = col;
//         while(row >= 0 && col >=0){ //upper diag
//             if(board[row][col] == 'Q')
//                 return false;
//             --row;
//             --col;
//         } 
        
//         col = dupcol;
//         row = duprow;
//         while(col >=0){
//             if(board[row][col] == 'Q')
//                 return false;
//             --col;
//         }
        
//         col = dupcol;
//         row = duprow;
//         while(row <board.size() && col >=0){
//             if(board[row][col] == 'Q')
//                 return false;
//             ++row;
//             --col;
//         }
//         return true;
//     }

    
    // void solve(int col, vector<vector<string>>&res, vector<string>&board, int n){
    //     if(col == n){
    //         res.push_back(board);
    //         return;
    //     }
    //     for(int row = 0; row <n ;++row){
    //         if(isSafe(row, col, board)){
    //             board[row][col] = 'Q';
    //             solve(col+1, res, board, n);
    //             board[row][col] = '.';
    //         }
    //     }
    // }

    void solve(int col, vector<vector<string>>&res, vector<string>&board, int n, vector<int>&left, vector<int>&upperD, vector<int>&lowerD){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row =0;row <n;++row){
            if(left[row] != 1 && upperD[n-1 + col - row] != 1 && lowerD[col+row] != 1){
                left[row] = 1;
                upperD[n-1+col-row] = 1;
                lowerD[col + row] = 1;
                board[row][col] = 'Q';
                solve(col+1,res,board,n,left,upperD,lowerD);
                left[row] = 0;
                upperD[n-1+col-row] = 0;
                lowerD[col + row] = 0;
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
        vector<int>left(n,0), upperD(2*n-1,0), lowerD(2*n-1,0);
        // solve(0,res,board,n);
        solve(0,res,board,n,left,upperD,lowerD);
        return res;
    }
};
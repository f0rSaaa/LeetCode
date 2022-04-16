class Solution {
public:
    
    bool isSafe(vector<vector<char>>&board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[row][i] == c) //cols
                return false;
            if(board[i][col] == c) //rows
                return false;
            if(board[(3*(row/3))+i/3][(3*(col/3))+i%3] == c)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    for(char c = '1';c <='9';c++){
                        if(isSafe(board,i,j,c)){
                            board[i][j] =c;    
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
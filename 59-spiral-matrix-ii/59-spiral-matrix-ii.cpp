class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left =0;
        int top = 0;
        int bottom = n-1;
        int right = n-1;
        vector<vector<int>>matrix(n,vector(n,0));
        int dir = 0;
        int counter = 1;
        while(left <= right && top <= bottom){
            if(dir == 0){
                for(int i=left;i<=right;i++){
                    matrix[top][i] = counter;
                    counter++;
                }
                top++;
            } else if(dir ==1){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right] = counter;
                    counter++;
                }
                right--;
            } else if(dir == 2){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i] = counter;
                    counter++;
                }
                bottom--;
            } else if(dir == 3){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left] = counter;
                    counter++;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return matrix;        
    }
};
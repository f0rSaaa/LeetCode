class Solution {
public:
    // int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
        
// 		// aux[i][j] is the sum of sub-matrix which start at [0][0] and end in [i][j]
//         // int[][] aux = new int[m + 1][n + 1]; // padding on top and left
//         vector<vector<int>>aux(m+1, vector<int>(n+1));
//         for (int i = 1; i < m + 1; i++) {
//             for (int j = 1; j < n + 1; j++) {
// 				// draw a picture, you will understand it easily~
//                 aux[i][j] = matrix[i - 1][j - 1] + aux[i - 1][j] + aux[i][j - 1] - aux[i - 1][j - 1]; 
//             }
//         }
        
//         int res = 0;
// 		// try each sub-matrix
//         for (int x1 = 1; x1 < m + 1; x1++) {
//             for (int y1 = 1; y1 < n + 1; y1++) {
//                 for (int x2 = x1; x2 < m + 1; x2++) {
//                     for (int y2 = y1; y2 < n + 1; y2++) {
//                         if (target == aux[x2][y2] - aux[x2][y1 - 1] - aux[x1 - 1][y2] + aux[x1 - 1][y1 - 1])
//                             res++;
//                     }
//                 }
//             }
//         }
        
//         return res;   
    int result=0,target;
    unordered_map<int,int> map;
    void get_result(vector<int>& nums)                          //Get number of subarrays that sum to target.
    {
        int sum=0;
        map.clear();
        map[0]++;
        for(int &i:nums)
        {
            sum+=i;
            result+=map[sum-target];       //get number of subarrays who's sum equals target and end at i and add result to global result.
            map[sum]++;                    //Add the occurence of running sum to map.
        }
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        this->target=target;
        vector<int> row(matrix[0].size());
        for(int i=0;i<matrix.size();i++)                    //Convert 2D array to 1D by row.
        {
            fill(row.begin(),row.end(),0);                  //Clear vector to start the row with i as starting row.
            for(int j=i;j<matrix.size();j++)
            {
                for(int x=0;x<matrix[0].size();x++)         //Add next row
                    row[x]+=matrix[j][x];
                get_result(row);
            }
        }
        return result;
    }
};
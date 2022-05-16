class Solution {
public:
//     bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
//         if(i <0 && j<0)
//             return true;
//         if(i<0 && j >=0){
//             while(j>=0){
//                 if(p[j] != '*')
//                     return false;
//                 j--;
//             }
//             return true;            
//         }

//         if(j<0 && i >=0){
//             return false;
//         }

//         if(dp[i][j] != false)
//             return dp[i][j];

//         if(s[i] == p[j] || p[j] == '?')
//             return dp[i][j] = solve(s,p,i-1,j-1,dp);
//         else {
//             if(p[j] == '*')
//                 return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
//             else 
//                 return dp[i][j] = 0;
//         }
//     }
    
    
    bool isAllStars(string & S1, int i) {

      // S1 is taken in 1-based indexing
      for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
          return false;
      }
      return true;
    }
    
    bool isMatch(string s, string p) {
    	int n = s.length();
        int m = p.length();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1,false));
        // return solve(s, p, n-1,m-1,dp);    
        dp[0][0] = true;
        for(int i=1;i<m+1;i++){
//             for(int ii = 1;ii<i+1;ii++){
//                 if(p[ii-1] != '*')
//                     dp[ii][i] = false;
                
//             }
            dp[0][i] = isAllStars(p,i);
        }
        for(int i=1;i<n+1;i++){
            dp[i][0] = false;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else {
                    if(p[j-1] == '*')
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
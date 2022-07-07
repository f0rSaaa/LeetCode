class Solution {
public:
    
//     int t[101][101][201];
//     bool solve(string s, string t, string st, int i, int j, int k, int n1, int n2, int n3){
//         if(i >= n1 && j >= n2 && k >= n3)
//             return true;
        
//         // if(dp[i][j][j] != -1)
//         //     return dp[i][j][k];
        
//         // if(i < n1 && st[k] == s[i] && solve(s,t,st,i+1,j,k+1,n1,n2,n3)){
//         //     return true;
//         // } else if(j < n2 && st[k] == t[j] && solve(s,t,st,i,j+1,k+1,n1,n2,n3))
//         //     return true;
//         // else 
//         //     return false;
        
//         if(k >= n3)
//             return false;
        
//         if(t[i][j][k] != -1)
//             return t[i][j][k];
        
//         return t[i][j][k] = ((s[i] == st[k] && solve(s,t,st,i+1,j,k+1,n1,n2,n3)) || (t[j] == st[k] && solve(s,t,st,i,j+1,k+1,n1,n2,n3)));
//     }
    
//     bool isInterleave(string s1, string s2, string s3) {
//         memset(t,-1,sizeof(t));
//         int n1 = s1.length();
//         int n2 = s2.length();
//         int n3 = s3.length();
//         if(n1 + n2 != n3)
//             return false;
//         vector<vector<vector<int>>>dp(n1, vector<vector<int>>(n2, vector<int>(n3,-1)));
//         return solve(s1,s2,s3,0,0,0,n1,n2,n3);
//     }
    
    int m, n, N;
    int t[101][101][201];
    bool check(string s1, string s2, string s3, int i, int j, int k) {
        if(i >= m && j >= n && k >= N) //solution
            return true;
        
        if(k >= N) //other string didn't get consumed whole
            return false;
            
        if(t[i][j][k] != -1)
            return t[i][j][k];
        
        return t[i][j][k] = ((s1[i]==s3[k] && check(s1, s2, s3, i+1, j, k+1)) || (s2[j]==s3[k] && check(s1, s2, s3, i, j+1, k+1)));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        N = s3.length();
        
        return check(s1, s2, s3, 0, 0, 0);
    }
};
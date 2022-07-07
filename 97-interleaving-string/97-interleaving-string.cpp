class Solution {
public:
    
    int dp[101][101][201];
    bool solve(string s, string t, string st, int i, int j, int k, int n1, int n2, int n3){
        if(i == n1 && j == n2 && k == n3)
            return true;        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        return dp[i][j][k] = ((s[i] == st[k] && solve(s,t,st,i+1,j,k+1,n1,n2,n3)) || (t[j] == st[k] && solve(s,t,st,i,j+1,k+1,n1,n2,n3)));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n1 + n2 != n3)
            return false;
        return solve(s1,s2,s3,0,0,0,n1,n2,n3);
    }

};
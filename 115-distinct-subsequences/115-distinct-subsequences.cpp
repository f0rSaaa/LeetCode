class Solution {
public:
    
int solve(string& t, string& s,int i, int j ,vector<vector<int>>&dp){
	
	if(j<0)
		return 1;
	if(i<0)
		return 0;
	
	if(dp[i][j] != -1)
		return dp[i][j];
	
	if(t[i] == s[j])
		return dp[i][j] = solve(t,s,i-1,j-1,dp) + solve(t,s,i-1,j,dp);
	else
		return dp[i][j] = solve(t,s,i-1,j,dp);

}
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};
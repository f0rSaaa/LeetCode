class Solution {
public:
    int solve(int idx, int size, int sum , string &s, vector<vector<int>>&dp){
        if(idx<0)
            return 0;
        
        if(dp[idx][size]!= -1)
            return dp[idx][size];
        
        int notpick = solve(idx-1, size,sum, s,dp);
        int pick = 0;
        if((sum-(s[idx]-'0')*pow(2,size))>=0)
            pick = 1 +solve(idx-1, size+1,(sum-(s[idx]-'0')*pow(2,size)), s,dp);
        
        return dp[idx][size] = max(pick, notpick);
    }
    
    int longestSubsequence(string s, int k) {
        int  n = s.length();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(n-1,0,k,s,dp);
    }
    
    
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<int>dp(n);
        dp[0] = 1;
        int c2 = 0, c3 =0, c5=0;
        for(int i=1;i<n;i++){
            dp[i] = min({dp[c2]*2,dp[c3]*3,dp[c5]*5});
            if(dp[i] == dp[c2]*2)
                c2++;
            if(dp[i] == dp[c3]*3)
                c3++;
            if(dp[i] == dp[c5]*5)
                c5++;
        }
        return dp[n-1];
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i == j)
                    dp[i][j] = 1;
            }
        }
        int start = 0;
        int maxL = 1;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                maxL = 2;
            }
        }
        for(int len = 3;len <=n;++len){
            for(int i=0;i<n-len+1;++i){
                int j = i+ len -1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    if(len > maxL){
                        start = i;
                        maxL = len;
                    }
                }
            }
        }

        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return s.substr(start, maxL);
    }
};
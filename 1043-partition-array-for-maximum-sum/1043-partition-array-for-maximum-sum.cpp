class Solution {
public:
    
    int solve(int i, int n, vector<int>&arr, int k, vector<int>&dp){
        if(i == n)
            return 0;
        int sum = 0;
        int res = INT_MIN;
        int maxE = INT_MIN;
        int len = 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxE = max(maxE, arr[j]);
            sum = len*maxE + solve(j+1,n,arr,k,dp);
            res = max(res, sum);
            
        }
        return dp[i] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int>dp(n,-1);
        // return solve(0,n,arr,k,dp);
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int sum = 0;
            int res = INT_MIN;
            int maxE = INT_MIN;
            int len = 0;


            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxE = max(maxE, arr[j]);
                sum = len*maxE + solve(j+1,n,arr,k,dp);
                res = max(res, sum);

            }
        dp[i] = res;
        }
        return dp[0];
    }
};
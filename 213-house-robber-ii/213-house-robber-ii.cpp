class Solution {
public:
    
    int solve(vector<int>&v, int idx, vector<int>&dp){
        if(idx == 0)
            return v[0];
        if(idx < 0)
            return 0;
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int pick = v[idx]+solve(v,idx-2,dp);
        int npick = solve(v,idx-1,dp);
        
        return dp[idx] = max(pick,npick);
    }
    
    int rob(vector<int>& nums) {
        vector<int>temp1, temp2;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int>dp(n-1,-1),dp1(n-1,-1);
        for(int i=0;i<n;i++){
            if(i != 0)
                temp1.push_back(nums[i]);
            if(i != n-1)
                temp2.push_back(nums[i]);
        }
        // for(auto it:temp1){
        //     cout << it << " ";
        // }
        // for(auto it:temp2){
        //     cout << it << " ";
        // }
        return max(solve(temp1,temp1.size()-1,dp),solve(temp2,temp2.size()-1,dp1));
    }
};
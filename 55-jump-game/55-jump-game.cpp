class Solution {
public:
    
    int dp[10005];
    bool solve(int idx, vector<int>&nums){
        if(idx == nums.size() -1)
            return true;
        if(idx >= nums.size())
            return false;
        if(dp[idx] != -1)
            return dp[idx];
        for(int i=1;i<=nums[idx];++i){
            if(solve(idx+i,nums))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0, nums);
    }
};
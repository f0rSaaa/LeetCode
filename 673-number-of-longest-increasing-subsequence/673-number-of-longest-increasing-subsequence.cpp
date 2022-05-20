class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    	int n = nums.size();
        int maxi = 1;
        vector<int>dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int pre = 0;pre<i;pre++){
                if(nums[pre]< nums[i] && dp[pre]+1> dp[i]){
                    dp[i] = dp[pre]+1;
                    //inherit copy same value
                    cnt[i] = cnt[pre];
                } else if(nums[pre]< nums[i] && dp[pre]+1 == dp[i]){
                    //got same numbner which can give the same value so we increment the value from there
                    cnt[i] +=cnt[pre];
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                count+=cnt[i];
            }
        }
        return count;    
    }
};
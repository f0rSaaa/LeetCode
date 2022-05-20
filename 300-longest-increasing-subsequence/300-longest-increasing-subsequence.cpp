class Solution {
public:
    
    int lb(vector<int>&dp, int x){
        int start = 0;
        int end = dp.size() -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(dp[mid]<x){
                start = mid+1;
            } else {
                end = mid -1;
            }
        }
        return start;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        vector<int>dp;
        int n = nums.size();
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]> dp.back()){
                dp.push_back(nums[i]);
                len++;
            } else {
    			int ind = lb(dp,nums[i]);
                // int ind = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[ind] = nums[i];
            }
        }

        return len;
    }
};
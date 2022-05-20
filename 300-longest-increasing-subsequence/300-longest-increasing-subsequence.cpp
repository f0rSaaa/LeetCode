class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

    	for(int ind=n-1;ind>=0;ind--){
    		for(int pre = ind-1;pre>=-1;pre--){
    			int len = 0 + dp[ind+1][pre+1];
    			if(pre == -1 || nums[ind]>nums[pre])
    				len = max(len, 1 + dp[ind+1][ind+1]);

    			dp[ind][pre+1] = len;
    		}
    	}
        return dp[0][0];
    }
};
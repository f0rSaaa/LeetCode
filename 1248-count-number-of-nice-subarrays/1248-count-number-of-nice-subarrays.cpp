class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        unordered_map<int, int>mpp;
        int sum = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum == k)
                res++;
            if(mpp.find(sum - k)!= mpp.end())
                res+=mpp[sum-k];
            mpp[sum]++;
        }
        return res;
    }
};
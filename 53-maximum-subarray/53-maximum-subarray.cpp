class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxS = nums[0];
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            maxS = max(curr, maxS);
            if(curr <0){
                curr = 0;
            }
        }
        return maxS;
    }
};
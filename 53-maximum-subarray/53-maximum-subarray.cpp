class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;   //var for cuurS
        int maxS = nums[0];     //var for maxS
        for(int i=0;i<nums.size();++i){
            curr += nums[i];    // inc the currsum element by element
            maxS = max(curr, maxS);     // update maxS if the curr sum exceeds the maxS
            if(curr <0){       //  if currS becomes negative the reset currS to 0 and start again
                curr = 0;
            }
        }
        return maxS;
    }
};
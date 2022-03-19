class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int>copy = nums;
        sort(copy.begin(),copy.end());
        unordered_map<int, int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(copy[i])!=mpp.end())
                continue;
            else
                mpp[copy[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = mpp[nums[i]];
        }
        return nums;
    }
};
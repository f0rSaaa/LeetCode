class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;++j){
            //if nums[i] and nums[j] are same dont do anything;
            if(nums[i]!= nums[j]){
                ++i;    //incrementing the ith pointer
                nums[i] = nums[j]; //overwriting the values
            }
        }
        return i+1;
    }
};
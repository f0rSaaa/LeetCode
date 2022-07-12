class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int>ans;
        while(low < high){
            // int sum = nums[low] + nums[high];
            if(nums[low] + nums[high] ==  target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            } else if(nums[low] + nums[high] < target)
                low++;
            else
                high--;
        }
        return {};
    }
};
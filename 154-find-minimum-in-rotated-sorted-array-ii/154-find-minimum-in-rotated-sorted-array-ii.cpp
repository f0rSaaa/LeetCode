class Solution {
public:
    int findMin(vector<int>& nums) {
        // return *min_element(begin(nums),end(nums));
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid]>nums[end])
                start = mid+1;
            else if(nums[mid]<nums[end])
                end = mid;
            else {
                if(nums[start] == nums[mid]){
                    start++;
                    end--;
                } else
                    end = mid;
            }
        }
        return nums[end];
    }
};
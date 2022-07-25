class Solution {
public:
    
    int first(vector<int>& nums, int x){
        int low = 0;
        int high = nums.size() -1;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low )/2;
            if(nums[mid] == x){
                res = mid;
                high = mid -1;
            } else if(nums[mid]>x){
                high = mid -1;
            } else {
                low = mid+1;
            }
        }
        return res;    
    }
    
    int last(vector<int>& nums, int x){
        int low = 0;
        int high = nums.size() -1;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low )/2;
            if(nums[mid] == x){
                res = mid;
                low = mid +1;
            } else if(nums[mid]>x){
                high = mid -1;
            } else {
                low = mid+1;
            }
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums, target);
        int l = last(nums, target);
        if(f == -1 || l == -1)
            return {-1,-1};
        return {f,l};
    }
};
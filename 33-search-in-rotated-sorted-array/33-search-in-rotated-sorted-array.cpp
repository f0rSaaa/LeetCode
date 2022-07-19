class Solution {
public:
    int findMinElem(vector<int>&nums){
        int l = 0;
        int n = nums.size();
        int h = nums.size() -1;
        while(l <=h){
            int m = l + (h-l)/2;
            int prev = (m + n-1) % n;
            int next = (m+1) % n;
            if(nums[m] < nums[prev] && nums[m] < nums[next])
                return m;
            else if(nums[m]>nums[h])
                l = m +1;
            else
                h = m - 1;
        }
        return -1;
    }
    
    
    int binarySearch(vector<int>&nums, int low, int high, int x){
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == x)
                return mid;
            else if(nums[mid]> x){
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target)
                return 0;
            return -1;
        }
        int pivot = findMinElem(nums);
        // cout << pivot << endl;
        int searchL = binarySearch(nums, 0, pivot-1, target);
        int searchR = binarySearch(nums,pivot,n-1,target);
        // cout << searchL << " "<< searchR << endl;
        if(searchL > -1)
            return searchL;
        if(searchR > -1)
            return searchR;
        return -1;
    }
    
};
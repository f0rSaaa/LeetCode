class Solution {
public:
    
    int firstO(vector<int>&arr, int x){
        int start = 0;
        int end = arr.size()- 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] > x)
                end = mid -1;
            else if(arr[mid] < x)
                start = mid +1;
            else if(mid == 0 || arr[mid] != arr[mid-1])
                return mid;
            else 
                end = mid -1;
        }
        return -1;
    }

    int lastO(vector<int>&arr, int x){
        int start = 0;
        int end = arr.size()- 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] > x)
                end = mid -1;
            else if(arr[mid] < x)
                start = mid +1;
            else if(mid == arr.size() - 1 || arr[mid] != arr[mid+1])
                return mid;
            else 
                start = mid + 1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo,lo;
        fo = firstO(nums, target);
        lo = lastO(nums, target);
        vector<int>ans;
        if(fo == -1) {
            return {-1,-1};
        } else {
            ans.push_back(fo);
            ans.push_back(lo);
        }
        return ans;    
    }
};
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
         if(arr.size() <3)
            return 0;
        //nhi ho raha iss se
        // for(int i=0;i<nums.size()-2;i++){
        //     int sum = target - nums[i];
        //     int low = i+1;
        //     int high = nums.size() - 1;
        //     cout << count << " ";
        //     while(low <= high){
        //         if(nums[low] + nums[high] == sum){
        //             count++;
        //             low++;
        //             high--;
        //         } else if(nums[low]+nums[high]<=sum){
        //             low++;
        //         } else {
        //             high--;
        //         }                
        //     } 
        // }
        // return count;
        
        //https://leetcode.com/problems/3sum-with-multiplicity/discuss/1123612/C%2B%2B-Super-Simple-7-line-Solution-Without-Sorting
        unordered_map<int, int> m;
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            res = (res + m[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++) {
                m[arr[i] + arr[j]]++;
            }
        }
        return res;

    }
};
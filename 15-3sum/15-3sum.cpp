class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();;
        if(n < 3)
            return {{}};
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for(int i =0;i<n-2;i++){
//             if(i ==0 || (i>0 && nums[i] != nums[i-1])){
                
//             }
            int sum = 0 - nums[i];
            int low=i+1;
            int high = n-1;
            while(low < high){
                if(nums[low] + nums[high] == sum ){
                    res.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1])
                        low++;
                    while(low < high && nums[high] == nums[high-1])
                        high--;
                    low++;
                    high--;
                } else if(nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
            while(i+1 <n && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};
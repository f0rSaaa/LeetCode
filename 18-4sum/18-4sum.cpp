class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;i++){
            long long tempS = target- nums[i];
            for(int j=i+1;j<nums.size()-2;j++){
                long long finalS = tempS - nums[j];
                int low = j+1;
                int high = nums.size() - 1;
                while(low < high){
                    if(nums[low] + nums[high] == finalS){
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low < high && nums[low] == nums[low+1]){
                            low++;
                        }
                        while(low < high && nums[high] == nums[high -1]){
                            high--;
                        }
                        low++;
                        high--;
                    } else if(nums[low] + nums[high] < finalS)
                        low++;
                    else
                        high--;   
                }
                while(j+1 < nums.size() && nums[j] == nums[j+1]){
                    j++;
                }
            } 
            while(i+1 <nums.size() && nums[i] == nums[i+1]){
                i++;
            }
        }
        return res;
        // vector<vector<int>>ans;
        // if(nums.size() < 4){
        //     return ans;
        // }
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-3;i++){
        //     int tt = target - nums[i]; 
        //     for(int j=i+1;j<nums.size()-2;j++){
        //         int ft = tt - nums[j];
        //         int low = j+1;
        //         int high = nums.size() -1;
        //         while(low < high){
        //             if(nums[low] + nums[high] == ft){
        //                 ans.push_back({nums[i],nums[j],nums[low],nums[high]});
        //                 while(low < high && nums[low] == nums[low+1])
        //                     low++;
        //                 while(low<high && nums[high] == nums[high - 1])
        //                     high--;
        //                 low++;
        //                 high--;
        //             } else if(nums[low] + nums[high]< ft)
        //                 low++;
        //             else 
        //                 high--;
        //         }
        //         while(j+1 < nums.size() && nums[j] == nums[j+1])
        //         j++;
        //     }
        //     while(i+1 < nums.size() && nums[i] == nums[i+1])
        //         i++;
        // }
        // return ans;
    }
};
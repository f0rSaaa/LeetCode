class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k,i;
        for(k = n-2;k>=0;k--){
            //from second last elemnet find elem which is less than the previus elem from right to left
            // 1 2 3 here it will be 2 as 2 < 3
            if(nums[k] < nums[k+1])
                break;
        }
        if(k < 0){ // the array was in descending order
            reverse(nums.begin(),nums.end());
        } else {    //find the first elem which is greater than the element at kth index from right side
            for(i = n-1;i>k;i--){
                if(nums[i]> nums[k])
                    break;   
            }
            swap(nums[i], nums[k]);
            reverse(nums.begin()+k+1, nums.end());
        }
            
    }
};
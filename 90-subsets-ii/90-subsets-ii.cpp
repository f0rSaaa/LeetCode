class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res,int n){
        // if(idx == n){
        //     res.push_back(temp);
        //     return;
        // }
        res.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i != idx && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,res,n);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,nums, temp,res,nums.size());
        return res;
    }
};
class Solution {
public: 
    
    void solve(vector<int>&nums, vector<vector<int>>&res, vector<int>&temp, vector<int>&freq){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i] = 1;
                temp.push_back(nums[i]);
                solve(nums,res,temp,freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        vector<int>freq(nums.size(),0);
        solve(nums,res,v,freq);
        return res;
    }
};
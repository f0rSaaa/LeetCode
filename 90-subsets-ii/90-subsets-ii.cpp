class Solution {
public:
    void solve(int idx, vector<int>&nums,vector<int>&temp, set<vector<int>>&s, int n){
        if(idx == n){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(idx+1,nums,temp,s,n);
        temp.pop_back();
        solve(idx+1, nums, temp, s, n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        set<vector<int>>s;
        solve(0,nums, temp,s,nums.size());
        for(auto it:s){
            res.push_back(it);
        }
        return res;
    }
};
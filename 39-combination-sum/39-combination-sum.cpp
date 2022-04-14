// #include<bits/stdc++.h>
class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&res, vector<int>&v, int idx){
        if(target == 0){
            res.push_back(v);
            return;
        }
        for(int i=idx;i<candidates.size() && target >=candidates[i];i++){
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i],res,v,i);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>v;
        solve(candidates, target, res,v, 0);
        return res;
    }
};
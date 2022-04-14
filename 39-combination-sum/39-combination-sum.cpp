
class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&res, vector<int>temp, int idx){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(idx == candidates.size()){
            if(target == 0){
                res.push_back(temp);
            }
            return;
        }
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            solve(candidates, target-candidates[idx],res,temp,idx);
            temp.pop_back();
        }
 
        solve(candidates,target,res, temp,idx+1);
    }    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        solve(candidates, target, res,v, 0);
        return res;
    }
};
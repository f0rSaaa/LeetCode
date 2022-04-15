class Solution {
public:
    void solve(vector<int>&candidates,int target, vector<vector<int>>&ans, vector<int>&temp, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]>target)
                return;
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans, temp,i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates, target,ans,temp,0);
        return ans;
    }
};
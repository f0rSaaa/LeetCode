class Solution {
public:
    void rec(int idx, int tar, vector<int>&can, vector<vector<int>>&res, vector<int>&temp){
        if(tar == 0){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<can.size() && tar >=can[i];++i){
            temp.push_back(can[i]);
            rec(i,tar-can[i],can, res, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        sort(can.begin(),can.end());
        vector<vector<int>>res;
        vector<int>temp;
        rec(0,t,can,res,temp);
        return res;
    }
};
class Solution {
public:
   void solve(int idx, int tar, vector<int>&temp, vector<vector<int>>&res, vector<int>&can){
       if(tar == 0){
           res.push_back(temp);
           return;
       }
       for(int i= idx;i<can.size() && can[i] <= tar; ++i){
           if(i > idx && can[i] == can[i-1])
               continue;
           temp.push_back(can[i]);
           solve(i+1,tar-can[i],temp, res, can);
           temp.pop_back();
       }
   } 
    
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(), can.end());
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,tar,temp,res,can);
        return res;
    }
};
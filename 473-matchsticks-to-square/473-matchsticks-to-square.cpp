class Solution {
public:
    
    bool backt(vector<int>&mat, vector<bool>&vis, int target, int curr_s, int i, int k){ //k is sides
        if(k == 1)
            return true;
        if(curr_s == target)        //if curr equals to target then reset curr sum and i to 0 and decrease a edge
            return backt(mat, vis, target, 0, 0, k-1);
        for(int j=i;j<mat.size();++j){
            if(vis[j]|| curr_s+mat[j]>target)
                continue;
            vis[j] = true;
            if(backt(mat, vis, target, curr_s+mat[j],j+1,k))
                return true;
            vis[j] = false;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(n < 4 || sum % 4 !=0)
            return false;
        vector<bool>vis(n,false);
        return backt(matchsticks,vis,sum/4,0,0,4);
    }
};
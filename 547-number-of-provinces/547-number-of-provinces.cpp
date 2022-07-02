class Solution {
public:
    
    //https://leetcode.com/problems/number-of-provinces/discuss/577731/C%2B%2B-Disjoint-Set-Union-with-Path-Compression-Optimization
    void dfs(vector<vector<int>>&M,vector<vector<int>>& vis,int i,int j){
        if(i<0 || i> M.size() || j<0 || j> M.size()) return ;
        vis[i][j]=1;
        vis[j][i]=1;
        for(int k=0;k<M[0].size();k++){
            if(!vis[j][k] && M[j][k] == 1) dfs(M,vis,j,k);
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && isConnected[i][j] == 1){
                    dfs(isConnected,vis, i,j);
                    count++;
                }
            }
        }
        return count;     
    }
};
class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<int>&v) {
        v[node]=1;
        for(auto it:adj[node]) {
            if(!v[it])
               dfs(it,adj,v);
                
        }
    
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        vector<int>adj[stones.size()];
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visit(stones.size(),0);
        int count=0;
        for(int i=0;i<stones.size();i++) {
            if(!visit[i]){
                dfs(i,adj,visit);
                count++;
            }
        }
        return stones.size()-count;
    }
};
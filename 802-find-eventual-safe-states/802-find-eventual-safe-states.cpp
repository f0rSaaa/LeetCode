class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse the graph and do topological sort
        
        int n = graph.size();
        vector<int>adj[n];
        vector<int>indeg(n,0);
        for(int i=0;i<n;++i){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(indeg[i] ==0)
                qu.push(i);
        }
        vector<int>res;
        while(!qu.empty()){
            int x = qu.front();
            qu.pop();
            res.push_back(x);
            for(auto it: adj[x]){
                indeg[it]--;
                if(indeg[it]==0)
                    qu.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
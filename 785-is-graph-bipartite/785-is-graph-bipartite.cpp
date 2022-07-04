class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int>color(n,0);  
        for(int i=0;i<n;++i){
            if(color[i] == 1 || color[i] == -1)
                continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                
                for(auto it: graph[x]){
                    if(!color[it]){
                        color[it] = -color[x];
                        q.push(it);
                    } else if(color[it] == color[x])
                       return false;
                }
            }
        }
        return true;
    
    }
};
class Solution {
public:
    

    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int>adj[n+1];
        for(auto it:dis){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map <int, int> color;
        for(int i = 1; i <= n; ++i) {
            queue<int> q;
            q.push(i);
            color.insert({i, 0});
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(auto &it:adj[node]){
                    int newColor = color[node] ^ 1;
                    // int newColor = 1 - color[node];
                    if(color.find(it) == color.end()){
                        color[it] = newColor;
                    } else if( color[it] == newColor)
                        continue;
                    else
                        return false;
                    
                    q.push(it);
                }
            }
        }
        return true;
    }
};
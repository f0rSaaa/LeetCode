class Solution {
public:
        
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int>adj[n+1];
        for(auto it:dis){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
//         unordered_map <int, int> color;
//         for(int i = 1; i <= n; ++i) {
//             queue<int> q;
//             q.push(i);
//             color.insert({i, 0});
//             while(!q.empty()) {
//                 int node = q.front();
//                 q.pop();
//                 for(auto &it:adj[node]){
//                     int newColor = color[node] ^ 1;
//                     // int newColor = 1 - color[node];
//                     if(color.find(it) == color.end()){
//                         color[it] = newColor;
//                     } else if( color[it] == newColor)
//                         continue;
//                     else
//                         return false;
                    
//                     q.push(it);
//                 }
//             }
//         }
//         return true;
        // int n = dis.size();
        queue<int> q;
        vector<int>color(n+1,0);  
        for(int i=1;i<=n;++i){
            if(color[i] == 1 || color[i] == -1)
                continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                
                for(auto it: adj[x]){
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
class Solution {
public:
    
    // bool isbipa(vector<int>adj[], vector<int>&color, int node){
    //     queue<int>qu;
    //     qu.push(node);
    //     color[node] = 1;
    //     while(!qu.empty()){
    //         int x = qu.front();
    //         qu.pop();
    //         for(auto it:adj[x]){
    //             if(color[x] == color[it])
    //                 return false;
    //             if(color[it] == -1){
    //                 // int newColor = 1- color[x];      
    //                 color[it] = 1- color[x];
    //                 qu.push(it);
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int>adj[n+1];
        for(auto it:dis){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map <int, int> color;
        // vector<int>color(n+1,-1);
        // for(int i=1;i<=n;++i){
        //     if(color[i] == -1)
        //         if(!isbipa(adj, color,i));
        //             return false;              
        // }
        for(int i = 1; i <= n; i++) {
            queue<int> q;
            q.push(i);
            color.insert({i, 0});
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(auto itr = adj[node].begin(); itr != adj[node].end(); itr++) {
                    // all neighbors of current node are given alternate color
                    int altColor = color[node]^1;
                    if(color.find(*itr) == color.end()) color.insert({*itr, altColor});
                    else if(color[*itr] == altColor)    continue;
                    else    return false;
                    
                    q.push(*itr);
                }
            }
        }
        return true;
    }
};
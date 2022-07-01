class Solution {
public:
//     void dfs(int node, stack<int>&st, vector<int>&vis, vector<int> adj[]){
//         vis[node] = 1;
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 dfs(it,st,vis,adj);
//             }
//         }
//         st.push(node);
//     }
    
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int>adj[num];
        vector<int>indeg(num,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        // vector<int>vis(num,0);
        // stack<int>st;
        // for(int i=0;i<num;i++){
        //     if(!vis[i]){
        //         dfs(i,st,vis,adj);
        //     }
        // }
        // vector<int>res;
        // while(!st.empty()){
        //     int x = st.top();
        //     st.pop();
        //     res.push_back(x);
        // }
        // return res;
        vector<int>res;
        queue<int>qu;
        for(int i=0;i<num;i++){
            if(indeg[i] == 0)
                qu.push(i);
        }
        int count = 0;
        while(!qu.empty()){
            int x =qu.front();
            qu.pop();
            res.push_back(x);
            count++;
            for(auto it:adj[x]){
                indeg[it]--;
                if(indeg[it] == 0){
                    qu.push(it);
                }
            }
        }
        if(count != num)
            return {};
        else
            return res;
    }
};
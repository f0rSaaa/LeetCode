class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
            // adj[it[0]].emplace_back(it[1],it[2]);

        }
        vector<int>dis(n+1, INT_MAX);
        vector<bool>vis(n+1, false);
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>minh;
        minh.push({0,k}); //dist and prev;
        dis[k] = 0;
        
        while(!minh.empty()){
            int dist = minh.top().first;
            int prev = minh.top().second;
            minh.pop();
            if(vis[prev])
                continue;
            vis[prev] = true;

            for(auto it:adj[prev]){
                int next = it.first;
                int nextdis = it.second;
                if(dis[next] > dis[prev]+nextdis){
                    dis[next] = dis[prev]+nextdis;
                    minh.push({dis[next],next});;
                }
            }
        }
        // for(auto it:dis){
        //     cout << it << " ";
        // }
        int res  = INT_MIN;

        for(int i=1;i<=n;i++){
            if(i == k)
                continue;
            res = max(res, dis[i]);
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
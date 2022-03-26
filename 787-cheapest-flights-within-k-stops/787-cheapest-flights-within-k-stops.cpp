class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //priority queue tle
        // priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>minH;
        // vector<pair<int, int>>adj[n];
        // for(auto it:flights){
        //     adj[it[0]].push_back({it[1],it[2]});
        // }
        // minH.push({0,{src,0}}); //cost, node, stops;
        // while(!minH.empty()){
        //     int cost = minH.top().first;
        //     int node = minH.top().second.first;
        //     int stops = minH.top().second.second;
        //     minH.pop();
        //     if(node == dst)
        //         return cost;
        //     if(stops>k)
        //         continue;
        //     for(auto it:adj[node]){
        //         minH.push({cost+it.second,{it.first,stops+1}});
        //     }
        // }
        // return -1;
        vector<int> dist(n, INT_MAX);
        vector<int> prev;
        dist[src]=0;
        for(int i = 0; i <= k; i++){
            prev=dist;
            for(auto x: flights){
                if(prev[x[0]]!=INT_MAX and dist[x[1]]>x[2]+prev[x[0]])
                    dist[x[1]]=x[2]+prev[x[0]];
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];     
    }
};
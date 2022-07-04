class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>qu;
        vector<bool>vis(n, false);
        qu.push(0);
        while(!qu.empty()){
            int x = qu.front();
            qu.pop();
            vis[x] = true;
            for(auto it: rooms[x]){
                if(!vis[it]){
                    qu.push(it);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;++i){
            if(vis[i])
                count++;
        }
        if(count == n)
            return true;
        return false;
    }
};
class Solution {
public:
//     vector<pair<int, int>>d = {{1,0},{0,1},{-1,0},{0,-1}};
//     void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int i, int j, int n, int m){
//         if(i <0 || j < 0 || i >=n || j >=m || grid[i][j] == 0)
//             return;
//         if(vis[i][j] == 1 || vis[j][i] == 1)
//             return;
//         vis[i][j] = 1;
//         vis[j][i] = 1;
//         // dfs(gird, vis, )
//         for(int k=0;k<4;++k){
//             int x = i+d[k].first;
//             int y = j+d[k].second;
//             dfs(grid, vis,x,y,n,m);
//         }
//         // dfs(grid, vis, i-1, j, n, m);
//         // dfs(grid, vis, i+1, j, n, m);
//         // dfs(grid, vis, i, j-1, n, m);
//         // dfs(grid, vis, i, j+1, n, m);
//     }
    
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int m = isConnected[0].size();
//         vector<vector<int>>vis(n, vector<int>(m,0));
//         int count = 0;
//         for(int i=0;i<n;++i){
//             for(int j=0;j<m;++j){
//                 if(!vis[i][j] && isConnected[i][j] == 1){
//                     dfs(isConnected,vis, i,j,n,m);
//                     count++;
//                 }
//             }
//         }
//         return count;    
//     }
        //It will be use to store groups
    vector<int> v;
    
    //Find the leader of any group in which x lies
    //if not lie in any group then it is self leader
    int parent(int x)
    {
        //self leader
        if(v[x]==-1) return x; 
        //find the leader of self parent
        return v[x]=parent(v[x]);
    }
    
    //Adding 2 friends in a group
    void _union(int a,int b)
    {
        //find the leader of both a and b
        int p_a=parent(a),p_b=parent(b);
        
        //if already in same group, i.e leader of both of them are same then return
        if(p_a==p_b) return; 
        /*
         if both of them are from different group then add both the groups 
         and make a single common group
         We can do this by -> leader of 1st group is member of 2nd group 
         and now main leader of whole group is leader of 2nd member
        */ 
        v[p_a]=p_b; //v[p_a] will store the index of leader of whole group
    }
    
    int findCircleNum(vector<vector<int>>& M) { 
        int n=M.size();
        v=vector<int> (n,-1);//there will be maximum n group, mark all as a leader
        
        //making group
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j])  //if i is friend of j, add them in a group
                { 
                    //if i is in any group then add j in that group
                    //or vice-versa
                    _union(i,j);  //Add them in a group
                }
            }
        }
        int c=0; 
        
        //counting group
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1) c++; //counting total number of parents
        }
        return c; 
    }
};

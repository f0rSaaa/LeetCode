class DSU{
// private:

    
public:
    
    vector<int>par, size;
    
    DSU(int n){
        par.resize(n);
        size.resize(n);
        
        for(int i=0;i<n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int x){
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    
    bool _union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px ==  py)
            return false;
        if(size[px] < size[py]){
            par[py] = px;
            size[py] +=size[px];
        } else {
            par[px] = py;
            size[px] +=size[py];
        }
        return true;
    }
    
};


class Solution {
public:
    
    //https://leetcode.com/problems/number-of-provinces/discuss/577731/C%2B%2B-Disjoint-Set-Union-with-Path-Compression-Optimization
    
    
    // void dfs(vector<vector<int>>&M,vector<vector<int>>& vis,int i,int j){
    //     if(i<0 || i> M.size() || j<0 || j> M.size()) return ;
    //     vis[i][j]=1;
    //     vis[j][i]=1;
    //     for(int k=0;k<M[0].size();++k){
    //         if(!vis[j][k] && M[j][k] == 1) dfs(M,vis,j,k);
    //     }
    //     return ;
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        // vector<vector<int>>vis(n, vector<int>(m,0));
        // int count = 0;
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         if(!vis[i][j] && isConnected[i][j] == 1){
        //             dfs(isConnected,vis, i,j);
        //             count++;
        //         }
        //     }
        // }
        // return count;     
        
        DSU dsu(n);
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                if(isConnected[i][j] == 1)
                    dsu._union(i,j);
            }
        }
        for(int i=0;i<n;i++){
            if(i == dsu.par[i])
                islands++;
        }
        return islands;
    }
};
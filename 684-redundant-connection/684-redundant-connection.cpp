class DSU{
private:
    vector<int>par, size;
    
public:
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() +1);;
        for(auto &it:edges){
            if(!dsu._union(it[0],it[1]))
                return it;
        }
        
        return {};
    }
};
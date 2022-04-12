class Solution {
public:
    void rotate(vector<int>&v){
        int n = v.size();
        int last = v[n-1];
        for(int i=n-2;i>=0;i--){
            v[i+1] = v[i];
        }
        v[0] = last;
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>v;
        for(auto it:grid){
            for(auto ix:it){
                v.push_back(ix);
            }
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        int elem = n*m;
        while(k--){
            rotate(v);
        }
        reverse(v.begin(), v.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j] = v.back();
                v.pop_back();
            }
        }
        return res;
    }
};
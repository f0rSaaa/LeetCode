class Solution {
public:
    bool solve(vector<int>&arr, int idx, vector<int>&vis){
        if(idx<0 || idx>=arr.size() || vis[idx] == 1)
            return false;
        if(arr[idx] == 0)
            return true;
        vis[idx] = 1;
        return solve(arr,idx+arr[idx],vis) || solve(arr,idx-arr[idx],vis);
    } 
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n,-1);
        return solve(arr,start,vis);
    }
};
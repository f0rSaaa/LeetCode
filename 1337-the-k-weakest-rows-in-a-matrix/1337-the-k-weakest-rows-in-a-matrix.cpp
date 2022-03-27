class Solution {
public:
    int binary(vector<int> m) {
        int l = 0;
        int h = m.size()-1;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, int>mpp;
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int count = binary(mat[i]);
            // int count = 0;
            // for(int j=0;j<m;j++){
            //     if(mat[i][j] == 1)
            //         count++;
            // }
            mpp[i] = count;
        }
        // for(auto it:mpp){
        //     cout << it.first << "" << it.second << endl;
        // }
        // cout << endl;
        priority_queue<pair<int, int>>maxH;
        for(auto it:mpp){
            maxH.push({it.second, it.first});
            if(maxH.size() > k)
                maxH.pop();
        }
        while(maxH.empty() == false){
            int x = maxH.top().second;
            maxH.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
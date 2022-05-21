class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // if(numRows == 0)
        //     return {{1}};
        if(numRows == 1)
            return {{1}};
        vector<vector<int>>res;
        res.push_back({1});
        // res[1].push_back({1,1});
        vector<int>ans;
        ans.push_back(1);
        ans.push_back(1);
        res.push_back(ans);
        // res[1]=ans;
        for(int i=2;i<numRows;i++) {
            vector<int>temp(ans.size()+1,1);
            for(int j=1;j<ans.size();j++) {
                temp[j] = ans[j-1] + ans[j];
            }
            ans = temp;
            // res[i]=ans;
            res.push_back(ans);
            temp.clear();
        }
        return res;    
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int>temp = intervals[0];
        vector<vector<int>>ans;
        for(auto it: intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1], temp[1]);
            } else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minH;
        unordered_map<int, int>mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto it:mpp){
            minH.push({it.second, it.first});
            if(minH.size() > k){
                minH.pop();
            }
        }
        vector<int>ans;
        while(!minH.empty()){
            int x = minH.top().second;
            minH.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>minh;
        for(auto i=mpp.begin();i!=mpp.end();i++){
            minh.push({i->second,i->first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(minh.size() > 0){
            int x = minh.top().second;
            minh.pop();
            ans.push_back(x);
        }
        return ans;        
    }
};
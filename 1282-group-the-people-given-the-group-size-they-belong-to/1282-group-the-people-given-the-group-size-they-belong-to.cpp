class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>>mpp;
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>res;
        for(auto it:mpp){
            vector<int> second = it.second;
            int gs = it.first;
            vector<int>temp;
            for(int i=0;i<second.size();i++){
                temp.push_back(second[i]);
                if(temp.size() == gs){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};
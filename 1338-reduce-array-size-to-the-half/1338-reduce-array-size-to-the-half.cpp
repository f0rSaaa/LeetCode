class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        priority_queue<pair<int, int>>maxH;
        for(auto it:mpp){
            maxH.push({it.second, it.first});
        }
        int count = 0;
        int k = arr.size();
        while( k > arr.size() / 2){
            k -= maxH.top().first;
            maxH.pop();
            count++;
            

        }
        return count;
    }
};
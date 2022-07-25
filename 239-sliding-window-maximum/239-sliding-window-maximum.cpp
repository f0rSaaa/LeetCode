class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n){
            int maxi = INT_MIN;
            for(auto it: nums){
                maxi = max(it, maxi);
            }
            return {maxi};
        }
        list<int>li;
        int i =0;
        int j =0;
        vector<int>res;
        while(j<n){
            while(li.size() > 0 && li.back() < nums[j]) {
                li.pop_back();
            }
            li.push_back(nums[j]);
            if(j-i+1 < k){
                ++j;
            } else if(j-i+1 == k){
                res.push_back(li.front());
                if(nums[i] == li.front()){
                    li.pop_front();
                }
                ++i;
                ++j;
            }
        }
        return res;
    }
};
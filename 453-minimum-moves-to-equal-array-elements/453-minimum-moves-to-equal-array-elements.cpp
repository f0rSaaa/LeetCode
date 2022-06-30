class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto itL:nums)
            mini = min(itL, mini);
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res += nums[i] - mini;
        }
        return res;
    }
};
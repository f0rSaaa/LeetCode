class Solution {
public:
    //https://leetcode.com/problems/wiggle-subsequence/discuss/1115385/Short-and-Easy-w-Explanation-or-O(N)-time-O(1)-Space
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        for(int i=0;i<n-1;i++) {
            int dif = nums[i+1] - nums[i];
            v.push_back(dif);
        }
        int i=0;
        int count = 1;
        int prevdiff = 0;
        while(i<v.size()){

            if((v[i]>0 && prevdiff<=0)||(v[i]<0 && prevdiff>=0)){
                count++;
                prevdiff = v[i];
            }
            i++;
        }
        return count;
    }
};
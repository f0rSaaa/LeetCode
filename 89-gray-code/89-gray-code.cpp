class Solution {
public:
    
    // https://leetcode.com/problems/gray-code/discuss/30028/4-lines-C%2B%2B-code.
    
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for (int i=0; i<(1<<n); i++) 
            ans[i] = i^(i>>1);
        return ans;    
    }
};
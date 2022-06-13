class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        vector<int>prefix(n,0);
        int odd = 0;
        for(int i=0;i<n;i++){
            prefix[odd]++;
            if(nums[i] % 2)
                odd++;
            if(odd >= k)
                res+=prefix[odd-k];
        }
        return res;    
    }
};
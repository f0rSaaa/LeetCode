class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;
        for(auto it: nums){
            if(s.find(it-1)== s.end()){
                int number = it;
                int streak = 1;
                while(s.find(number+1)!=s.end()){
                    number++;
                    streak++;
                }
                ans = max(ans, streak);
            }
        }
        return ans;
    }
};
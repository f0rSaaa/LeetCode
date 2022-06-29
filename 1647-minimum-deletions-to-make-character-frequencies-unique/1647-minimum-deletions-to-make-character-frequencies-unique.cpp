class Solution {
public:
    int minDeletions(string s) {
        vector<int> ans(26);
        int res = 0;
        for(auto x: s) ans[x - 'a']++;
        sort(ans.begin(), ans.end(), greater<>());
        
        for(int i = 1; i < 26; i++)
        {
            if(ans[i] == 0) break;
            if(ans[i] < ans[i-1]) continue;
                if(ans[i-1] == 0) {
                    res+=ans[i];
                    ans[i] = 0;
                }
                else {
                    res+=abs(ans[i-1]-ans[i])+1;
                    ans[i]=max(ans[i-1]-1, 0);
                }
        }
            return res;
    }
};
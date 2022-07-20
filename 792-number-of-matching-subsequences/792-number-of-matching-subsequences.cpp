class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int>mpp;
        for(auto it:words){
            mpp[it]++;
        }
        int res = 0;
        int m = s.size();
        for(auto it:mpp){
            int i =0;
            int j =0;
            int n = it.first.size();
            string t = it.first;
            while(i < n && j < m){
                if(t[i] == s[j]){
                    ++i;
                    ++j;
                } else {
                    ++j;
                }
            }
            if(i == n)
                res +=it.second;
        }
        return res;
    }

};
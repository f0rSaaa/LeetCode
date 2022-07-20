class Solution {
public:
    bool isSub(string s, string& t){     //t big string s small string
        int n = s.size();
        int m = t.size();
        int i=0;
        int j=0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                ++i;
                ++j;
            }else
                ++j;
        }
        if(i == n)
            return true;
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int>mpp;
        for(auto it:words){
            mpp[it]++;
        }
        int res = 0;
        for(auto it:mpp){
            if(isSub(it.first,s))
                res+=it.second;
        }
        return res;
    }
};
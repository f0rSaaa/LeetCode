class Solution {
public:
    int strStr(string haystack, string needle) {
        // string s = needle + '#' + haystack;
        string s = needle;
        s+='#';
        s+=haystack;
        int n = s.size();
        int patLen = needle.size();
        vector<int>lps(n,0);
        int i = 1;
        int len = 0;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len > 0){
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        for(auto it:lps){
            cout << it << " ";
        }
        cout << endl;
        int res = -1;
        for(int i=0;i<n;++i){
            if(lps[i] == patLen){
                res = i -lps[i] - patLen;
                break;
            }
        }
        return res;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>mpp;
        mpp.insert({'I',1});
        mpp.insert({'V',5});
        mpp.insert({'X',10});
        mpp.insert({'L',50});
        mpp.insert({'C',100});
        mpp.insert({'D',500});
        mpp.insert({'M',1000});
        
        int n = s.size();
        int res = mpp[s[n-1]];
        for(int i=n-2;i>=0;--i){
            if(mpp[s[i]] < mpp[s[i+1]]){
                res -= mpp[s[i]];
            } else {
                res += mpp[s[i]];
            }
        }
        return res;
    }
};
class Solution {
public:
    bool checkZeroOnes(string s) {
        int c1 =0;
        int c0 = 0;
        int n = s.size();
        int m1 = INT_MIN, m2 = INT_MIN;
        for(int i=0;i<n;++i){
            if(s[i] == '1'){
                c1++;
                if(s[i]!= s[i+1]){
                    m1 = max(m1, c1);
                    c1 = 0;
                }
            } else {
                c0++;
                if(s[i]!= s[i+1]){
                    m2 = max(m2, c0);
                    c0 = 0;
                }
            }  
        }
        if(m1 > m2)
            return true;
        return false;
    }
};
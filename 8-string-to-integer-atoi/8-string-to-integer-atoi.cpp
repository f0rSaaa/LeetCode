class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long res =0;
        int sign = 1;
        for(int i=0;i<n;++i){
            while(s[i] == ' '){
                ++i;
            }
            cout << i << endl;
            // if(s.empty() || i == n-1)
            //     return 0;
            if(s[i]=='-'|| s[i]=='+'){
                sign = s[i] == '-'?-1:1;
                ++i;
            }
            while(s[i] >='0' && s[i] <='9'){
                res = res * 10 + (s[i]-'0');
                ++i;
                if(res*sign >= INT_MAX){
                    return INT_MAX;
                }
                if(res*sign <= INT_MIN){
                    return INT_MIN;
                }
            }
            return res*sign;
        }
        return 0;
    }
};
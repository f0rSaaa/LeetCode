class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        string s = "11";
        for(int i=3;i<=n;++i){
            string temp ="";
            s+='#';
            int m= s.size();
            int count = 1;
            for(int j=1;j<m;++j){
                if(s[j] == s[j-1])
                    count++;
                else {
                    temp += to_string(count);
                    temp += s[j-1];
                    count = 1;
                }
            }
            s = temp;
        }
        return s;
    }
};
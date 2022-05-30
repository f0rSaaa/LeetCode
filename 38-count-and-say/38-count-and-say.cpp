class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        string s = "11";
        for(int i=3;i<=n;i++){
            string temp = "";
            int count = 1;
            s+='#';               //to denote the end of the string
            int m = s.length();
            for(int j=1;j<m;j++){
                if(s[j] == s[j-1])
                    count++;
                else {
                    temp+=to_string(count);
                    temp+=s[j-1];
                    count = 1;
                }
            }
            s = temp;
        }
        return s;
    }
};
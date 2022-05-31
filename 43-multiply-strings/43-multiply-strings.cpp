class Solution {
public:
    string multiply(string num1, string num2) {
        int  n = num1.length();
        int  m = num2.length();
        string res(m+n,'0');
        for(int i = n-1;i>=0;i--){
            int carry = 0;
            for(int j = m-1;j>=0;j--){
                int temp = (res[i+j+1]-'0')+ (num1[i]-'0') * (num2[j] - '0') + carry;
                res[i+j+1] = (temp % 10) + '0';
                carry = temp / 10;
            }
            res[i] += carry;
        }
        cout << res << endl;
        size_t start = res.find_first_not_of("0");
        if(start != string::npos)
            return res.substr(start);
        return "0";  
    }
};
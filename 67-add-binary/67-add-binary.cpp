class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length())
            return addBinary(b,a);
        int diff = b.length() - a.length();
        string padbits;
        for(int i=0;i<diff;i++){
            padbits+='0';
        }
        a =  padbits + a;
        string res = "";
        char carry ;
        for(int i = a.length() - 1;i>=0;i--){
            if(a[i] == '0' && b[i] == '0'){
                if(carry == '1'){
                    res+='1';
                    carry = '0';
                } else {
                    res+='0';
                    carry = '0';
                }
            } else if(a[i] == '1' && b[i] == '1'){
                if(carry == '1'){
                    res+='1';
                    carry = '1';
                } else {
                    res+='0';
                    carry = '1';
                } 
            }else if(a[i] != b[i]){
                 if(carry == '1'){
                    res+='0';
                    carry = '1';
                } else {
                    res+='1';
                    carry = '0';
                }
            }
        }
        if(carry == '1')
            res+='1';
        reverse(res.begin(),res.end());
        return res;

    }
};
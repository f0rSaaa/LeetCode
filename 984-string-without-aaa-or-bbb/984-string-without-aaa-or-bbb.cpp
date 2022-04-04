class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s="";
        while(a != 0 && b!=0){
            if(a>b){
                s+="aab";
                a--;
            } else if(b>a){
                s+="bba";
                b--;
            } else {
                s+="ab";
            }
            a--;
            b--;
        }
        while(a!=0){
            s+='a';
            a--;
        }
        while(b!=0){
            s+='b';
            b--;
        }
        return s;

    }
};
class Solution {
public:
    string convertToTitle(int cN) {
        string res="";
        while(cN){
            cN--;
            res += 'A' + cN%26;
            cN/=26;
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
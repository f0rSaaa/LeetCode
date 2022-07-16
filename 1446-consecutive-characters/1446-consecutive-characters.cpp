class Solution {
public:
    int maxPower(string s) {
        int i =0;
        int j;
        int n = s.length();
        int res=0;
        while(i<n){
            j = i+1;
            while(j<n && s[j]== s[j-1]){
                j++;
            }
            res = max(res, j-i);
            // ++i;
            i=j;
        }
        return res;
    }
};
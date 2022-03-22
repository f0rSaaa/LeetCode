class Solution {
public:
    
    //https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/1871662/JavaC%2B%2B-Easiest-Possible-Exaplained!!
    string getSmallestString(int n, int k) {
        string s = "";
        for(int i=0;i<n;i++){
            s+='a';
        }
        k-=n;
        int i = n-1;
        while(k){
            s[i] += min(25,k);
            k-=min(25,k);
            i--;
        }
        return s;
    }
};
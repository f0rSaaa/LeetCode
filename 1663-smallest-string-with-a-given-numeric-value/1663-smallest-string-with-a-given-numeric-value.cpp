class Solution {
public:
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
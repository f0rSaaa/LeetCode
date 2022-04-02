class Solution {
public:
    
    // int solve(string s, string rs, int n, int m){
    //     int t[n+1][m+1];
    //     for(int i=0;i<=n;i++){
    //         for(int j=0;j<=m;j++){
    //             if(i == 0 || j ==0)
    //                 t[i][j] = 0;
    //         }
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(s[n-1] == rs[m-1]){
    //                 t[i][j] = 1+t[i-1][j-1];
    //             } else {
    //                 t[i][j] =  max(t[i-1][j],t[i][j-1]);
    //             }
    //         }
    //     }
    //     return t[n][m];
    // }
    
    bool validPalindrome(string s) {
        // string rs = s;
        // reverse(s.begin(),s.end());
        // int  l =solve(s,rs,s.length(),rs.length());
        // cout<< l <<endl;
        // if(s.length() - l >1)
        //     return false;
        // return true;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                // cout << i1 <<" " <<j1 <<" "<<i2 <<" " <<j2<<endl;
                while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};
                while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};
                // cout << i1 <<" " <<j1 <<" "<<i2 <<" " <<j2<<endl;
                return i1 >= j1 || i2 >= j2;
            }
        return true;
    }
};
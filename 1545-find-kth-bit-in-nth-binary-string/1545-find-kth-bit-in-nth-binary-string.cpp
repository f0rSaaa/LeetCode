class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(n--){
            string rs = s;
            reverse(rs.begin(),rs.end());
            for(auto &it:rs){
                if(it == '0')
                    it = '1';
                else
                    it = '0';
            }
            // s = s +'1'+rs;
            s+='1'+rs;
        }
        return s[k-1];
    }
};
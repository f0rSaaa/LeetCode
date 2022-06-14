class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        string ans="";
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0))
            ans+='-';

        long  n = labs(numerator), d = labs(denominator), r = n %d;
        ans +=to_string(n/d);
        if(r == 0)
            return ans;
        ans+='.';
        cout << r << endl;
        unordered_map<long , int>mpp;
        while(r){       //INSERTING ( WHERE WE FIRST FOUND THE  REPEATING NUMBER
            if (mpp.find(r) != mpp.end()) {
                ans.insert(mpp[r], "(");
                ans += ')';
                break;
            }
            mpp[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        for(auto it:mpp){
            cout << it.first << " " << it.second << endl;
        }
        return ans;    

        // unordered_map<long, int> rs;
        // while (r) {
        //     if (rs.find(r) != rs.end()) {
        //         ans.insert(rs[r], "(");
        //         ans += ')';
        //         break;
        //     }
        //     rs[r] = ans.size();
        //     r *= 10;
        //     ans += to_string(r / d);
        //     r %= d;
        // }
        // return ans;
    }
};
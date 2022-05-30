class Solution {
public:
    double myPow(double x, int n) {
        long N = abs(n);
        double res = 1;
        while (N > 0) {
            if(N % 2 ==0){  //not for negatvive values
                x *= x;
                N /= 2;
            } else {
                res *=x;
                N--;
            }
        }
        cout << res << endl;
        return n>=0?res:1/res;
    }
};
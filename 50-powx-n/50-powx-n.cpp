class Solution {
public:
    double myPow(double x, int n) {
        long N = abs(n);
        double res= 1;
        while(N){
            if(N%2 == 0){
                x *=x;
                N/=2;
            } else {
                res*=x;
                N--;
            }
        }
        if(n < 0)     //if res is negative then return reciprocal of it
            return 1/res;
        return res;
    }
};
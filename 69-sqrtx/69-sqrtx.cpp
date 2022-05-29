class Solution {
public:
    int mySqrt(int x) {
        // return pow(x,0.5);
        long r = x;
        while(r*r >  x){
            r = (r + x/r) / 2;
        }
        return r;
    }
    
};
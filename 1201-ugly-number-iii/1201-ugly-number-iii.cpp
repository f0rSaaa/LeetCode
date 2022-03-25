class Solution {
public:
    // is function se tle aa raha //can memomize it using table
    // int gcd(long a, long b){
    //     if(a == 0)
    //         return b;
    //     if(b == 0)
    //         return a;
    //     if(a == b)
    //         return a;
    //     if(a>b)
    //         return gcd(a-b,b);
    //     else
    //         return gcd(a, b-a);
    // }
    
    // int gcd(int a, int b) {
    //     return b == 0 ? a : gcd(b, a % b);    
    // }
    
    int gcd(int a, int b){
        while(b != 0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long start = 0;
        long end =  2*1e9;
        long A = long(a), B = long(b), C = long(c);
        // long lcmAB = (A*B) / __gcd(A,B);
        // long lcmBC = (B*C) / __gcd(B,C);
        // long lcmAC = (A*C) / __gcd(A,C);
        // long lcmABC = (lcmAB*C) / __gcd(lcmAB,C);
        long lcmAB = (A*B) / gcd(A,B);
        long lcmBC = (B*C) / gcd(B,C);
        long lcmAC = (A*C) / gcd(A,C);
        long lcmABC = (lcmAB*C) / gcd(lcmAB,C);
        
        while(start < end){
            int mid = start + (end-start)/2;
            int count = mid/A + mid/B + mid/C -(mid/lcmAB + mid/lcmBC + mid/lcmAC) + mid/lcmABC;
            if(count < n){
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};
class Solution {
public:
    int mySqrt(int x) {
        // return pow(x,0.5);
        //nweton method
        // long r = x;
        // while(r*r >  x){
        //     r = (r + x/r) / 2;
        // }
        // return r;
        //binary search
        long long start = 0;
        long long end = INT_MAX;
        long long ans = 0;
        while(start <= end){
            long long mid = start + (end-start)/2;
            if(mid * mid == x)
                return mid;
            else if(mid * mid > x)
                end =  mid -1;
            else{
                ans = mid;
                start = mid+1;    
            }
        }
        return ans;
    }
    
};
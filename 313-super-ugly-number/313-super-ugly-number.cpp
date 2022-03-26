class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>res(n);
        vector<long long>cpy(primes.begin(),primes.end());
        int k = primes.size();
        vector<int>idx(k, 0);
        res[0] = 1;
        for(int i=1;i<n;i++){
            int temp = INT_MAX;
            for(int j=0;j<k;j++){
                temp = min(temp, primes[j]);
            }
            res[i] = temp;
            for(int j=0;j<k;j++){
                if(temp == primes[j]){
                    idx[j]++; 
                    primes[j]= res[idx[j]]*cpy[j];
                }
            }
        }
        return res[n-1];
    }
};
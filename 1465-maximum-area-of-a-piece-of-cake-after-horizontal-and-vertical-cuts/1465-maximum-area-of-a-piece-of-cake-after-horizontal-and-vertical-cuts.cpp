class Solution {
public:
    int mod = 1e9+7;
    
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        vector<int>length, width;
        int n = hc.size(), m = vc.size();
        length.push_back(hc[0]-0);
        width.push_back(vc[0]-0);
        for(int i= 1;i<n;++i){
            length.push_back(hc[i]-hc[i-1]);
        }
        for(int i=1;i<m;++i){
            width.push_back(vc[i]-vc[i-1]);
        }
        length.push_back(h-hc[n-1]);
        width.push_back(w-vc[m-1]);
//         for(auto it: length){
//             cout << it << " ";
            
//         }
//         cout << endl;;
//         for(auto it: width){
//             cout << it << " ";
//         }
        long long int maxL = LONG_MIN, maxW = INT_MIN;
        for(auto it:length){
            // maxL = max(maxL, it);
            if(maxL<it){
                maxL = it;
            }
        }
        for(auto it:width){
            // maxW = max(maxW, it);
            if(maxW<it){
                maxW = it;
            }            
        }
        
        return (maxL*maxW)%mod;
        
    }
};
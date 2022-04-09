class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second){
                int freq = it.second;
                for(int i=0;i<k;i++){
                    if(mpp[it.first+i]<freq)
                        return false;
                    else
                        mpp[it.first+i] -= freq;
                }
            }
        }
        return true;
    }
};
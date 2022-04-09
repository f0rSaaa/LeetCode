class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second){
                int freq = it.second;
                for(int i=0;i<groupSize;i++){
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
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int>mpp;
        for(auto it:tops){
            mpp[it]++;
        }
        for(auto it:bottoms){
            mpp[it]++;
        }
        int num = INT_MIN;
        int freq = 0;
        for(auto it:mpp){
            if(freq < it.second){
                freq =  it.second;
                num = it.first;
            }
        }
        // cout << num << " ";
        int topC = 0;
        int bottomC = 0;
        for(int i=0;i<tops.size();i++){
            if(tops[i] == num && bottoms[i] == num)
                continue;
            if(tops[i] != num && bottoms[i] != num){
                return -1;
            }
            if(tops[i]!=num)
                topC++;
            if(bottoms[i]!=num)
                bottomC++;
        }
        int res = min(topC, bottomC);
        return res;
    }
};
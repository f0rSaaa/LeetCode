class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
            // if(a[1] == b[1])
            //     return a[0] < b[0];
            return a[1]<b[1];  
        });

        int endP = intervals[0][1];
        int res = 1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= endP){
                res++;
                endP = intervals[i][1];
            }
        }
        return intervals.size() - res;    
    }
};
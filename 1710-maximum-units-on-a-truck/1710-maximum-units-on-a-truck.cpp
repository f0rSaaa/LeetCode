class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        int n = box.size();
        sort(box.begin(), box.end(),[](vector<int>&a, vector<int>&b){
            return a[1] > b[1];
        });
        int res = 0;
//         for(auto ot:box){
//             for(auto it:ot){
//                 cout << it << " ";
                
//             }
//             cout <<endl;
//         }
        for(int i=0;i<n;i++){
            if(truckSize == 0)
                break;
            res += box[i][1] * min(truckSize, box[i][0]);
            truckSize -= min(truckSize, box[i][0]);
        }
        return res;
    }
};
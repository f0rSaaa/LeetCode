class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        for(int i=0;i<n-1;i++) {
            int dif = nums[i+1] - nums[i];
            v.push_back(dif);
        }
        // for(auto it:v){
        //     cout << it << " ";
        // }
        // cout << endl;
        int i=0;
        int count = 1;
        // int currdiff;
        int prevdiff = 0;
        while(i<v.size()){
            // if(v[i]>0 && v[i+1]<0){
            //     count++;
            //     i++;
            // } else if(v[i]<0 && v[i+1]>0){
            //     count++;
            //     i++;
            // } else if((v[i] >0 && v[i+1] > 0) || (v[i] <0 && v[i+1] < 0)){
            //     while((v[i] >0 && v[i+1] > 0) || (v[i] <0 && v[i+1] < 0)){
            //         i++;
            //     }
            // }
            if((v[i]>0 && prevdiff<=0)||(v[i]<0 && prevdiff>=0)){
                count++;
                prevdiff = v[i];
            }
            i++;
        }
        return count;
    }
};
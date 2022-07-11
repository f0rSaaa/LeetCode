class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = 0;
        int can2 = 0;
        int c1 = 0;
        int c2 = 0;
        // for(auto it:nums){
        //     if(c1 == 0){
        //         can1 = it;
        //         c1= 1;
        //     } else if(c2 == 0){
        //         can2=it;
        //         c2=1;
        //     } else if(it == can1){
        //         c1++;
        //     } else if(it == can2){
        //         c2++;
        //     } else {
        //         c1--;
        //         c2--;
        //     }
        // }
        for(auto it:nums){
            if(it == can1){
                c1++;
            }else if(it == can2){
                c2++;
            }else if(c1 == 0){
                can1 = it;
                c1 = 1;
            }else if(c2 == 0){
                can2 = it;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        int c = nums.size()/3;
        for(auto it:nums){
            if(it==can1)
                c1++;
            else if(it == can2)
                c2++;
        }
        vector<int>ans;
        if(c1 > c){
            ans.push_back(can1);
        }
        if(c2 > c){
            ans.push_back(can2);
        }
        return ans;
    }
};
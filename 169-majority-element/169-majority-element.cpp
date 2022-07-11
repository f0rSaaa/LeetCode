class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int can = 0;
        for(auto it:nums){
            if(count == 0)
                can = it;
            if(can == it)
                count++;
            else
                count--;
        }
        count = 0;
        for(auto it:nums){
            if(it == can)
                count++;
        }
        if(count  > nums.size()/2)
            return can;
        return 0;
    }
};
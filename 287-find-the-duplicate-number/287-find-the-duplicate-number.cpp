class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowP = nums[0];
        int fastP = nums[0];
        do{
            slowP = nums[slowP];
            fastP = nums[nums[fastP]];
        } while (slowP != fastP);
        
        fastP = nums[0];
        while(slowP!= fastP){
            slowP = nums[slowP];
            fastP = nums[fastP];
        }
        return slowP;    
    }
};
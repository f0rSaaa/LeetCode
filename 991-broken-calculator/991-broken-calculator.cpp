class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(target > startValue){
            if(target % 2 == 0){
                count++;
                target/=2;
            } else {
                count++;
                target++;
            }
        }
        return count+(startValue- target);
    }
};
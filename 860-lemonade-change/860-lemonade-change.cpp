class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0;
        int c10 = 0;
        for(auto it:bills){
            if(it == 5)
                c5++;
            else if(it == 10)
                c5--,c10++;
            else if(it == 20)
                if(c10 > 0)
                    c10--,c5--;
                else
                    c5-=3;
            if(c5<0)
                return false;
        }
        return true;

    }
};
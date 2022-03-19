class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = n-2;
        int onesC = 0;
        while(i>=0 && bits[i]==1){
            onesC++;
            i--;
        }
        if(onesC % 2 == 0)
            return true;
        return false;
    }
};
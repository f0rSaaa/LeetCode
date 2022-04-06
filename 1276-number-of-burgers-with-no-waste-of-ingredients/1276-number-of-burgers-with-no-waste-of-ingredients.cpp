class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        int jumbo =  t/2-c;
        int small = c-jumbo;
        if((jumbo>=0 && small >=0) && (4*jumbo+2*small == t) && (jumbo+small == c))
            return {jumbo,small};
        return {};
    }
};
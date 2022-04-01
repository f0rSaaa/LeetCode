class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalreq = 0;
        int currentGas = 0;
        int start = 0;
        int n = gas.size();
        for(int i=0;i<gas.size();i++){
            int diff =  gas[i] - cost[i];
            totalreq += diff;
            currentGas +=diff;
            if(currentGas < 0){
                start = i+1;
                currentGas = 0;
            }
        }
        if(totalreq<0)
            return -1;
        return start;
    }
};
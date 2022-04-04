class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0;
        int score = 0;
        int i=0;
        int j=tokens.size() - 1;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                res = max(res, score);
                i++;
            } else if(score > 0){
                power+=tokens[j];
                score--;
                j--;
                
            } else {
                break;
            }
        }
        return res;
    }
};
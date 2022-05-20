class Solution {
public:
    
   int check(string &s1,string &s2){
        if(s1.size() != s2.size() +1)
            return  false;
        int i = 0;
        int  j =0;
        while(i < s1.length()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            } else {
                i++;
            }
        }
        if(i == s1.size() && j == s2.size())
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
    	int n = words.size();
        int maxi = 1;
        sort(words.begin(),words.end(), [](string &s, string &t){
            return s.length() < t.length();
        });
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int pre = 0; pre < i;pre++){
                if(check(words[i],words[pre]) && 1 + dp[pre] > dp[i])
                    dp[i] = 1 + dp[pre];
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;    
    }
};
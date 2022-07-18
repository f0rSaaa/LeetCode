class Solution {
public:
//     bool solve(int idx, string& s, vector<string>&dict, vector<bool>&dp, unordered_set<string>&st){
//         if(idx == s.size()){
//             return true;
//         }
//         if(dp[idx] != false)
//             return dp[idx];
//         for(int i=idx;i<s.size();++i){
//             string aux = s.substr(idx,i-idx+1);
//             // bool flag = false;
//             // for(auto it:dict){
//             //     if(it.compare(aux) == 0){
//             //         // flag = true;
//             //         // break;
//             //         if(solve(i+1,s,dict,dp))
//             //             return dp[idx] = true;
//             //     }
//             // }
//             if(st.find(aux) != st.end()){
//                 if(solve(i+1,s,dict,dp,st))
//                     return dp[idx] = true;
//             }
//             // if(flag){
//             //     if(solve(i+1,s,dict,dp))
//             //         return dp[idx] = true;
//             // }
            
//         }
//         return dp[idx] = false;
//     }
    
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> d(wordDict.begin(), wordDict.end());
//         vector<bool>dp(wordDict.size(),false);
//         return solve(0,s,wordDict,dp,s);
//     }
    
    bool helper(const string& s, int start, const unordered_set<string>& d, vector<int>& memo) {
        if (start == s.size()) {
            return true;
        }
        
        if (memo[start] != -1) return memo[start];
        
        for (int i = start + 1; i <= s.size(); ++i) {
            const string sub = s.substr(start, i - start); 
            if (d.count(sub) == 1) {
                if (helper(s, i, d, memo)) {
                    memo[start] = 1;
                    return true;
                }
            }
        }
        
        memo[start] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> d(wordDict.begin(), wordDict.end());
		// Use a vector since we can index from 0 to N. 
		// Possible values in vector are: -1, 0, 1.
        vector<int> memo(s.length(), -1); 
        return helper(s, 0, d, memo);
    }
    
};
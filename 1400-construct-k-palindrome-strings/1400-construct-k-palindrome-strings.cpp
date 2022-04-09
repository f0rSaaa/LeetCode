class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()){
            return false;
        }
        if(k == s.length())
            return true;
        vector<int>freq(26);
        for(auto it :s){
            freq[it-'a']++;
        }
        int oddC = 0;
        for(int i=0;i<26;i++){
            if(freq[i] % 2 != 0){
                oddC++;
            }
        }
        return oddC <=k;
    }
};
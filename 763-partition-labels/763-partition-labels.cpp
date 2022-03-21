class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for( auto c: s)  mp[c]++;
        int i=0;
        vector<int>ans;
        unordered_map<char,int>mp1;
        for( int c=0 ; c<s.size() ; c++){
            mp1[s[c]]=1;     // cur char
            mp[s[c]]--;
            if(mp[s[c]]==0){
               mp1.erase(s[c]);
               if(mp1.size()==0){
                     ans.push_back(c-i+1);
                     i=c+1;
                }
             }
        }

        return ans;
    }
};
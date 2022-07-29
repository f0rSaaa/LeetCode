class Solution {
public:
    vector<int> makePattern(string s){
        if(s.size() == 0)
            return {};
        vector<int>v;
        unordered_map<int, int>mpp;
        // for(auto it:s){
        //     mpp[it]++;
        // }
        int idx = 0;
        for(int i=0;i<s.size();++i){
            if(mpp.find(s[i])!= mpp.end()){
                v.push_back(mpp[s[i]]);
            } else {
                mpp[s[i]] = idx;
                idx++;
                v.push_back(mpp[s[i]]);
            }
        }
        return v;

    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int>pat = makePattern(pattern);
        for(auto it:pat){
            cout << it << " ";
        }
        vector<string>res;
        for(int i=0;i<words.size();++i){
            vector<int>aux = makePattern(words[i]);
            for(auto it:aux){
                cout << it << " ";
            }
            if(pat == aux){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
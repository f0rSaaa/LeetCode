class Solution {
public:
    bool  ispalin(string & s, int i, int j){
        while(i<j){
            if(s[i]!= s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    
    void rec(int idx, string &s, vector<string>&temp, vector<vector<string>>&res){
        if(idx == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();++i){
            if(ispalin(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));      //substr from first, last-first +1 
                rec(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        rec(0,s,temp,res);
        return res;
    }
};
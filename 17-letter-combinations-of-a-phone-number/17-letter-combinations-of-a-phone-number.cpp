class Solution {
public:
    
    void solve(int idx, string& tres, vector<string>&v, vector<string>&ans, string num){
        if(idx == num.size()){
            ans.push_back(tres);
            return;
        }

        for(int i=0;i<v[num[idx]-'0'].size();i++){
            tres.push_back(v[num[idx]-'0'][i]);
            solve(idx+1,tres,v,ans, num);
            tres.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        vector<string>ans;
        if(digits.size()==0)
            return ans;
        solve(0,s,v,ans,digits);
        return ans;    
    }
};
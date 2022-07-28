class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m){
            return false;
        }
        vector<int>v(256,0);
        for(auto it:s){
            v[it]++;
        }
        for(auto it:t){
            v[it]--;
        }
        for(auto it:v){
            if(it >=1)
                return false;
        }
        return true;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(auto it:t)
            mp[it]++;
        int count = mp.size();
        int i=0;
        int j=0;
        int len = INT_MAX;
        int start;
        string res="";
        while(j<s.length()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }  
            if(count > 0){
                j++;
            } else if(count==0){
                if(len > j-i+1){
                    len = j-i+1;
                    start = i;
                }
                while(count == 0){
                    if(mp.find(s[i])!= mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                            if(len > j-i+1){
                                len = j-i+1;
                                start = i;
                            }
                        }
                        i++;
                    }
                    else
                        i++;
                }
                j++;
            }
        }
        if(len == INT_MAX)
            return res;
        else 
            return res+=s.substr(start,len); 
    }
};
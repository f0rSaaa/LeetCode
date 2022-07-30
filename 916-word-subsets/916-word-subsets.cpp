class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int>maxF;
        for(auto it:words2){
            unordered_map<char, int>aux;
            for(auto ix:it){
                aux[ix]++;
            }
            for(auto  ix:aux){
                maxF[ix.first] = max(maxF[ix.first],aux[ix.first]);
            }
        }
        
        // for(auto it:maxF){
        //     cout << it.first << " " << it.second<< endl;
        // }
        vector<string>res;
        unordered_map<char, int>wMap;
        for(auto s:words1){
            wMap.clear();
            for(auto it:s){
                wMap[it]++;
            }
            
            bool flag = true;
            for(auto it:maxF){
                if(maxF[it.first] > wMap[it.first]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                res.push_back(s);
            }
            
        }
        
        return res;
    }
};
class Solution {
public:     
            //x , parent
    int findpar(char c, unordered_map<char, char>&mpp){
        if(c == mpp[c])
            return c;
        return mpp[c] = findpar(mpp[c], mpp);
    }
 	// int findpar(char x, unordered_map<char, char>& parent) {
 	// 	if (parent[x] != x) parent[x] = findpar(parent[x], parent);
 	// return parent[x];
 	// }
    
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char>mpp;
        for(auto it:equations){
            mpp[it[0]] = it[0];
            mpp[it[3]] = it[3];
        } 
        for(auto it:mpp){
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
        for(auto it:equations){
            char x = findpar(it[0], mpp);
            char y = findpar(it[3], mpp);
            
            if(it[1]=='=')
                mpp[y] = x;
        }
        
        for(auto it:equations){
            char x = findpar(it[0], mpp);
            char y = findpar(it[3], mpp);
        
            if(x == y && it[1] == '!')
                return false;
        }
        return true;   
    }
};
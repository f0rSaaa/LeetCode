class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        // int s1c = 0, s2c = 0;
        bool f1 = true, f2 = true;
        for(int i=0;i<s1.length();i++){
            if(s1[i]<s2[i]){
                f1 = false;
            } else if(s1[i]>s2[i]){
                f2 = false;
            }
        }
        if(f1 || f2)
            return true;
        return false;
    }
    
};
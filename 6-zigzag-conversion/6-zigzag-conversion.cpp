class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        vector<string>v(numRows);
        int n = s.length();
        int step = 1;
        int row = 0;
        for(int i=0;i<n;i++){
            v[row].push_back(s[i]);
            if(row == 0)
                step = 1;
            else if(row == numRows -1)
                step =-1;
            row+=step;
        }
        string res ="";
        for(int i= 0;i<v.size();i++){
            res+=v[i];
        }
        return res;
    }
};
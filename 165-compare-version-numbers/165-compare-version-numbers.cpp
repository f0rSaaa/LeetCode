class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size();
        int m = v2.size();
        int i =0 ;
        int j =0;
        int res;
        while(i< n || j < m){
            string s1 = "", s2="";
            while(i<n && v1[i] != '.'){
                // while(s1.size() == 0 && v1[i] == '0'){      //removing leading zeros
                //     i++;
                // }
                if(s1.size() == 0 && v1[i] == '0'){
                    i++;
                    continue;
                }
                s1 +=v1[i];
                ++i;
 
            }
            while(j<m && v2[j] != '.'){
                // while(s2.size() == 0 && v2[j] == '0'){
                //     j++;
                // }
                if(s2.size() == 0 && v2[j] == '0'){
                    j++;
                    continue;
                }
                s2 +=v2[j];
                ++j;
            }
            if(s1.size() > s2.size())
                return 1;
            else if(s2.size() > s1.size())
                return -1;
            
            res = s1.compare(s2);
            if(res < 0)
                return -1;
            else if(res > 0)
                return 1;
            // cout << s1 << endl;
            // cout << s2 << endl;
            ++i;
            ++j;
        }
        return 0;
    }
};
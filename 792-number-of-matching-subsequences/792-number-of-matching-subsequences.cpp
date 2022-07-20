class Solution {
public:
//     bool isSub(string s, string& t){     //t big string s small string
//         int n = s.size();
//         int m = t.size();
//         int i=0;
//         int j=0;
//         while(j < m){
//             if(s[i] == t[j]){
//                 ++i;
//                 ++j;
//             }else
//                 ++j;
//         }
//         return (i ==n);
//     }
    
    int numMatchingSubseq(string s, vector<string>& words) {
//         unordered_map<string, int>mpp;
//         for(auto it:words){
//             mpp[it]++;
//         }
//         int res = 0;
//         for(auto it:mpp){
//             if(isSub(it.first,s))
//                 res+=it.second;
//         }
//         return res;
//     }
     int count=0,k=s.size();
      //we will be form map to count occurences of particular word to avoid re calculation and this will reduce time
      unordered_map<string,int>mymap;
      for(int i=0;i<words.size();i++)
        mymap[words[i]]++;
      for(auto x:mymap)
      {
        int start1=0,start2=0;
        string p=x.first;
        int m=p.size();
        while(start1<k&&start2<m)
        {
          if(p[start2]==s[start1])
            start1++,start2++;
          else
            start1++;
        }if(start2==m)
          count+=x.second;//if we reach the length of string p then this word in in our string s. so we increase our count by number of times it occured in words instead of increamenting by 1
      }return count;
    }
};
class Solution {
public:
    
    int minimumDeletions(string s) {
        stack<char>st;
        int res = 0;
//         for(int i=s.length()-1;i>=0;i--){
//             if(!st.empty() && st.top()<s[i]){
//                 res++;
//                 st.pop();

//             } else 
//                 st.push(s[i]);
//         }
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()>s[i]){
                res++;
                st.pop();

            } else 
                st.push(s[i]);
        }
        return res;
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int count = 0;
        for(int i=0;i<s.length();i++){
        
            if(s[i]=='('){
                st.push('(');
            }else if(s[i]==')'){
                if(st.size()>0 && st.top() == '(')
                    st.pop();
                else
                    count++;
            }
        }
        return st.size()+count;
    }
};
class Solution {
public:
    
    bool isMatching(char x, char y){
        if(x == '}' && y == '{')
            return true;
        else if(x == ']' && y == '[')
            return true;
        else if(x == ')' && y == '(')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
                if(st.empty())
                    return false;
                else if(isMatching(s[i],st.top()) == true)
                    st.pop();
                else
                    return false;;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
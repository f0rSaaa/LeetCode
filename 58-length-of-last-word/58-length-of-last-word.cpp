class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int right = s.size() - 1;
        while(right>=0 && s[right] == ' ')
            right--;
        while(right>=0 && s[right] != ' '){
            length++;
            right--;
        }
        return length;
    }
};
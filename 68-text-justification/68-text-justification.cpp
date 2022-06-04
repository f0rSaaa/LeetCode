class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res, temp;
        string s;
        int len = 0;
        for(int i=0;i<words.size();i++){
            if(len + temp.size() + words[i].size() <= maxWidth){       //filling words in line
                temp.push_back(words[i]);
                len += words[i].size();
            } else {
                if(temp.size() == 1){          //one word occupies full line
                    s = temp[0];
                    s.append(maxWidth-s.size(),' ');
                    res.push_back(s);
                } else if(temp.size() > 1) {
                    int div = (maxWidth-len) / (temp.size() -1);       //for equal spaces in between words
                    int mod = (maxWidth-len) % (temp.size() -1);       //to prioritize the first space after first word
                    s = temp[0];
                    for(int j=1;j<temp.size();j++){
                        if(j<= mod) 
                            s.append(div+1,' ');        //one more space
                        else
                            s.append(div,' ');
                        s+=temp[j];
                    }
                    res.push_back(s);
                }
                temp.clear();
                temp.push_back(words[i]);
                len = words[i].size();
            }
        }

        s = temp[0];
        for(int j=1;j<temp.size();j++)
            s+= ' '+temp[j];
        s.append(maxWidth-s.size(),' ');
        res.push_back(s);

        return res;   
    }
};
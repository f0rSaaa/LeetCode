class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1)
            return {{1}};
        vector<vector<int>>res;
        res.push_back({1});
        vector<int>aux;
        aux.push_back(1);
        aux.push_back(1);
        res.push_back(aux);
        if(n==2)
            return res;
        for(int i=2;i<n;++i){
            vector<int>aux2(aux.size()+1,1);
            for(int j=1;j<aux.size();++j){
                aux2[j] = aux[j-1]+aux[j];
            }
            res.push_back(aux2);
            swap(aux,aux2);
        }
        return res;
    }
};
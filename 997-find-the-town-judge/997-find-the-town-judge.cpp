class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<int>indeg(n+1,0);
        // vector<int>outdeg(n+1,0);
        // for(auto &it:trust){
        //     indeg[it[1]]++;
        //     outdeg[it[0]]++;
        // }
        // for(int i=1;i<=n;i++){
        //     if(outdeg[i]==0 && indeg[i] == n-1){
        //         return i;
        //     }
        // }
        // return -1;
        vector<int>count(n+1,0);
        for(auto &it:trust){
            count[it[0]]--;
            count[it[1]]++;
        }
        for(int i=1;i<=n;++i){
            if(count[i] == n-1)
                return i;
        }
        return -1;
    }
};
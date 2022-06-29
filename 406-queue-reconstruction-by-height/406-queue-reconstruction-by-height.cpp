class Solution {
public:
    
    static bool compare(vector<int> a, vector<int>  b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> ans(people.size(),vector<int>(2, -1));
        for(int i = 0; i < people.size(); i++){
            int count = 0;
            for(int j = 0; j < ans.size(); j++){
                if(count == people[i][1] and ans[j][0] == -1){
                    ans[j] = people[i];
                    break;
                }
                else if(ans[j][0] == -1 or ans[j][0] == people[i][0]) count++;
            }
        }
        return ans;
        
    }
};
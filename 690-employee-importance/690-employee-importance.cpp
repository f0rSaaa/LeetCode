/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        unordered_map<int, Employee*>mpp;
        for(auto &it:emp){
            mpp[it->id] = it;
        }
        queue<Employee*>qu;
        qu.push(mpp[id]);
        int ans = 0;
        while(!qu.empty()){
            auto x = qu.front();
            qu.pop();
            ans +=x->importance;
            for(auto it:x->subordinates){
                qu.push(mpp[it]);
            }    
        }
        return ans;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>minH;
        for(int i=0;i<matrix.size();++i){
            minH.push({matrix[i][0],{i,0}});
        }
        for(int i=0;i<k-1;++i){
            int x = minH.top().second.first;
            int y = minH.top().second.second;
            minH.pop();
            if(y+1 <matrix.size()){
                minH.push({matrix[x][y+1],{x,y+1}});
            }
        }
        return minH.top().first;

    }
};
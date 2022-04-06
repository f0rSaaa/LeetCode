class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int c) {
        int tp = 0;
        sort(trips.begin(),trips.end(), [](vector<int>&a, vector<int>&b){
           if(a[1] == b[1])
               return a[2]<b[2];
            return a[1]<b[1];
            
        });
        for(auto it:trips){
            for(auto ix:it){
                cout << ix << " ";
            }
            cout << endl;
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
        for(int i=0;i<trips.size();i++){

            // if(i+1 < trips.size() && trips[i][2]<=trips[i+1][1]){
            //     tp-=trips[i][0];
            //     tp+=trips[i+1][0];
            // } else {
            //     tp+=trips[i][0];    
            // } 
            pq.push({trips[i][2],trips[i][0]}); 
            tp+=trips[i][0];
            
            while(pq.empty() == false && pq.top().first <= trips[i][1]){
                tp-=pq.top().second;
                pq.pop();
            }
            if(tp>c)
                return false;
        }
      
        return true;
    }
};
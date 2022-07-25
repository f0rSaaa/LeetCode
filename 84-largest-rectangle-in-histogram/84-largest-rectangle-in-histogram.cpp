class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // int pleft = -1;
        // int pright = n;
        vector<int>right, left;
        stack<pair<int, int>>st;
        for(int i=0;i<n;++i){
            if(st.size() == 0){
                left.push_back(-1);
            } else if(st.size() > 0 && st.top().first < heights[i]){
                left.push_back(st.top().second);
            } else if(st.size() > 0 && st.top().first >= heights[i]){
                while(st.size() > 0 && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size() == 0)
                    left.push_back(-1);
                else
                    left.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;--i){
            if(st.size() == 0){
                right.push_back(n);
            } else if(st.size() > 0 && st.top().first < heights[i]){
                right.push_back(st.top().second);
            } else if(st.size() > 0 && st.top().first >= heights[i]){
                while(st.size() > 0 && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size() == 0)
                    right.push_back(n);
                else
                    right.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        int res = INT_MIN;
        for(int i=0;i<n;++i){
            res = max(res, (right[i]-left[i]-1)*heights[i]);
        }
        return res;
    }
};
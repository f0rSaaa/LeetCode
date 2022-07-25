class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        stack<int>st;
        // st.push(nums[n-1]);
        for(int i=2*n-1;i>=0;--i){
            while(st.size() > 0 && st.top() <= nums[i%n])
                st.pop();
            if(i < n){
                if(st.size() == 0)
                    res[i] = -1;
                else
                    res[i] = st.top();                
            }

            st.push(nums[i% n]);
        }
        return res;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // vector<int>left(n), right(n), water(n);
        // left[0] = height[0];
        // right[n-1] = height[n-1];
        // for(int i=1;i<n;++i){
        //     left[i]= max(left[i-1], height[i]);
        // }
        // // for(auto it:left)
        // //     cout << it << " ";
        // // cout << endl;
        // for(int i= n-2;i>=0;--i){
        //     right[i] = max(right[i+1], height[i]);
        // }
        // // for(auto it:right)
        // //     cout << it << " ";
        // // cout << endl;
        // for(int i=0;i<n;++i){
        //     water[i] = min(left[i],right[i]) - height[i];
        // }
        // // for(auto it:water){
        // //     cout << it << " ";
        // // }
        // // cout << endl;
        // int ans = accumulate(water.begin(), water.end(),0);
        // return ans;
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
    }
};
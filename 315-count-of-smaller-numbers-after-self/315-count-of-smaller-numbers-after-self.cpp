class Solution {
public:
//     //binary search TLE     62/65
//     int binaryS(vector<int>&v, int target){
//         int low =0;
//         int high = v.size() -1;
//         while(low <= high){
//             int mid = low + (high-low)/2;
//             if(v[mid]>=target){         // for same element v[mid]> target will fail find the lower bound 
//                 high  = mid-1;
//             } else {
//                 low = mid +1;
//             }
//         }
//         return low;
//     }
    
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>res(n,0),aux;    //aux is sorted nums array that will be constructed on the go
//         for(int i=n-1;i>=0;--i){
//             int x = binaryS(aux,nums[i]);
//             res[i] = x;
//             aux.insert(aux.begin()+x, nums[i]);
//         }
//         return res;
//     }
    
    void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= right) {
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first) { 
                tmp[k++] = v[j++];
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid) {
            tmp[k++] = v[i++];
        }
        while (j <= right) {
            tmp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
            v[i] = tmp[i-left];
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) {
        if (left >= right) 
            return;

        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();

        vector<pair<int, int> > v(N);
        for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);
        // sorting in descending order
        mergeSort(count, v, 0, N-1);

        return count;
    }
};
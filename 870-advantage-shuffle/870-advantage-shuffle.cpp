class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>ms(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++){
            auto it = *ms.rbegin() > nums2[i] ? ms.upper_bound(nums2[i]) : ms.begin();
            nums1[i] = *it;
            ms.erase(it);
        }
        return nums1;
    }
};
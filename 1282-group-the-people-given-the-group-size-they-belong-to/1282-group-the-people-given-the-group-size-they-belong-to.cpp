bool comp(pair<int,int> &a,pair<int,int> &b)
{
    return a.first < b.first;
}
    class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
    vector<vector<int>> arr;
        vector<pair<int,int>> a;
        vector<int> ar;
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            a.emplace_back(nums[i],i);
        }
        sort(a.begin(),a.end(),comp);
        int coun = 0;
        for(auto x:a)
        {
            if(coun <= 0)
            {coun = x.first-1;
             if(!ar.empty())
                 arr.push_back(ar);
             ar = {};
            ar.push_back(x.second);
            }
            else
            {
                ar.push_back(x.second);
                coun--;
            }
            
    }
        if(!ar.empty())
            arr.push_back(ar);
        return arr;
    }
    
};
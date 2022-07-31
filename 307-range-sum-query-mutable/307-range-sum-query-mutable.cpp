class NumArray {
public:
    vector<int>fen, a;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        fen.resize(n+1,0);
        for(auto it:nums){
            a.push_back(it);
        }
        
        for(int i=0;i<n;++i){
            initialize(i,a[i]);
        }
    }
    
    void initialize(int i, int val){
        i++;
        while(i<= n){
            fen[i] +=val;
            i += (i & (-i));
        }
    }
    
    int sum(int i){
        i++;
        int s = 0;
        while(i>0){
            s+=fen[i];
            i -=(i & (-i));
        }
        return s;
    }
    
    void update(int index, int val) {
        int diff = val - a[index];
        a[index] = val;
        initialize(index,diff);
    }

    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
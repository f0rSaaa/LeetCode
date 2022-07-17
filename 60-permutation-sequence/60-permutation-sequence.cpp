class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>nums;
        for(int i=1;i<n;i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string res="";
        --k;
        while(true){
            res= res+to_string(nums[k/fact]);       // placing elem at the first index
            nums.erase(nums.begin()+k/fact);        // erasing the plced elem from the array nums
            if(nums.size() == 0)
                break;
            k=k %fact;                              //new value of k since they are placed in blocks and it skip many elements
            fact = fact / nums.size();              //new value of factorial
        }
        return res;
    }
};
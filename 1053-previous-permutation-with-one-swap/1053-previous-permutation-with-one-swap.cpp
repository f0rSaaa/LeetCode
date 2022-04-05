class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int leftV =arr.size() - 2;
        int rightV =arr.size() - 1;
        // int n = arr.size() - 1;
        while(leftV >=0 && arr[leftV]<=arr[leftV+1])
            leftV--;
        if(leftV <0)
            return arr;
        while(arr[rightV] >= arr[leftV])
            rightV--;
        while(arr[rightV] == arr[rightV-1])
            rightV--;
        swap(arr[leftV],arr[rightV]);
        // cout << leftV << " "<< rightV;
        
        return arr;
    }
};
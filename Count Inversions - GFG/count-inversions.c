// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.

long long merge(long long arr[], long long temp[], int low, int mid, int high){
    long long i, j, k;
    long long invCount = 0;
    i = low;
    j = mid;
    k = low;
    while((i<= mid - 1) && (j <= high)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount =  invCount + (mid - i);
        }
    }
    while(i <= mid - 1){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i];
    }
    return invCount;
}


long long invCount(long long arr[], long long temp[], int low, int high){
    long long mid , invC = 0;
    if(low < high){
        mid = (low +  high)/2;
        invC += invCount(arr, temp, low, mid);
        invC += invCount(arr, temp, mid+1, high);
        invC += merge(arr, temp, low, mid+1, high);
    }
    return invC;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    long long int ans  =  invCount(arr,temp,0,N-1);
    return ans;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends
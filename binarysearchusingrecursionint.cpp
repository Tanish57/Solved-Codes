#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int s, int e, int k){
    
    // base case:

    //element not found
    if(s>e)
        return -1;
    
    int mid = s + (e-s) /2;
    //element found
    if(arr[mid] == k)
        return mid;

    if(arr[mid] < k){
        return solve(arr, mid+1, e, k);
    }
    else{
        return solve(arr,s, mid-1, k);
    }
}
int binarySearch(int *input, int n, int val)
{
    int ans = solve(input, 0, n-1, val);
    return ans;
    //Write your code here
}

int main()
{
    int arr[6] = {2,4,6,10,14,18};
    int size = 6;
    int key = 18;

    int ans = binarySearch(arr, size, key);
    if(ans == -1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index "<<ans<<endl;
    }
    return 0;
}
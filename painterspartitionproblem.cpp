#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int k, int mid){
    int paitercount = 1;
    int boardSum = 0;
    
    for(int i=0; i<n; i++){
        if(boardSum + arr[i] <= mid){
            boardSum += arr[i];
        }
        else{
            paitercount++;
            if(paitercount > k || arr[i] > mid){
                return false;
            }
            boardSum = arr[i];
        }
    }
    return true;
}
int painterPartition(vector<int> arr, int n, int k) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    
    while(s<=e){
        if(isPossible(arr,n,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 5, 5, 5};
    cout<<painterPartition(arr, 4, 2)<<endl;
    return 0;
}
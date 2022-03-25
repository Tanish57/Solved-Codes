#include<bits/stdc++.h>
using namespace std;

void count(int arr[], int n){

    int k=arr[0];     //maximum element denoted by k, it will tell us how many elements would be there in the count array
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    int ans =0;
    for(int i=0;i<n; i++){
        ans = ans^count[i];
    }
    if(ans==0){
        cout<<"False";
    }
    else{
        cout<<"true";
    }
}
int main()
{
    int arr[6] = {1, 2, 2, 1, 1, 3};
    count(arr, 6);
    return 0;
}
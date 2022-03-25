#include<bits/stdc++.h>
using namespace std;

int sumarray(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size; i++){
        sum += arr[i] ;
    }
    return sum;
}

int main()
{
    int size; cin>>size;

    int arr[100];

    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }

    cout<<sumarray(arr, size);
    return 0;
}
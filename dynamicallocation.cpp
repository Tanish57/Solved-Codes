#include<bits/stdc++.h>
using namespace std;

int getSum(int *arr, int n){
    
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main()
{
    //dynamic array:
    int n;
    cin >> n;
    int* arr = new int[n];  // dynamically creating an array of variable size in heap memory;

    //taking input in array
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout << arr[i] <<" ";
    }cout<<endl;
    
    cout << "Sum of array is : " << getSum(arr, n) << endl;
    return 0;
}
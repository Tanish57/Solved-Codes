#include<bits/stdc++.h>
using namespace std;

int getMax(int num[], int size){
    int maxi = INT_MIN;

    for(int i = 0; i < size; i++){
        maxi = max(maxi, num[i]);       //max is a predefined function used to find the maximum between 2 values
        // if(num[i] > maxi){
        //     maxi = num[i];        //way to find maximum manually
        // }
    }

    return maxi;
}

int getMin(int num[], int size){
    int mini = INT_MAX;

    for(int i = 0; i < size; i++){
        mini = min(mini, num[i]);
        // if(num[i] < mini){
        //     mini = num[i];
        // }
    }

    return mini;
}

void printArray(int arr[], int size){
    for(int i =0; i<size ;i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size; cin>>size;

    int num[100];

    // taking input in array
    for(int i=0;i<size;i++){
        cin>>num[i];
    }cout<<endl;

    cout<<"max value is "<<getMax(num, size);
    cout<<endl;
    cout<<"min value is "<<getMin(num, size);
    cout<<endl;
    printArray(num, size);
    return 0;
}
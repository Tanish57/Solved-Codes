#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i =0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(vector<int> arr, int n){
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> arr = {1, 7, 9, 2, 3, 0};
    selectionSort(arr, 6);
    cout<<"Sorted array is: ";
    printArray(arr, 6);
    return 0;
}
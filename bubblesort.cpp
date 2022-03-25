#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i = 1; i<n; i++){
        //for round 1 to n-1
        for(int j = 0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printarray(vector<int> arr, int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{
    vector<int> arr = {10, 1, 7, 6, 14, 9};
    bubbleSort(arr, 6);
    printarray(arr, 6);
    return 0;
}
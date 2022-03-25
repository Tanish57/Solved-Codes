#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i = 1; i<n; i++){
        int temp = arr[i];
        //we're assuming 0th element is already sorted and then try to sort from the 1st index to the last one
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
            }
            else{ //ruk jao
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void printArray(vector<int> arr, int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> arr = {10, 1, 7, 4, 8, 2, 11};
    int n = 7;

    insertionSort(n, arr);
    printArray(arr, n);
    return 0;
}
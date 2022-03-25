#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    while(start <= end){

        if(arr[mid] == key){
            return mid;
        }
        
        if(key > arr[mid]){
            start =  mid+1;
        }
        else{
            end  = mid-1;
        }

        mid = start + (end-start)/2;
    }

    return -1;
}

int main()
{
    int odd[5] = {3, 8, 11, 14, 16};
    int even[6] = {2, 4, 6, 8, 12, 18};

    cout<<binarySearch(odd, 5, 14)<<endl;
    cout<<binarySearch(even, 6, 12)<<endl;
    return 0;
}
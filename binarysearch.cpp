#include<bits/stdc++.h>
using namespace std;

void print(int *arr, int s, int e){
    cout<<"start is "<<s<<" end is "<<e<<endl;
    int mid = s + (e-s)/2;
    for(int i=s; i<=e; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"mid element is "<<arr[mid]<<endl<<endl;
}

bool binarySearch(int *arr, int s, int e, int k){
    
    print(arr,s,e);
    // base case:

    //element not found
    if(s>e)
        return false;
    
    int mid = s + (e-s) /2;
    //element found
    if(arr[mid] == k)
        return true;

    if(arr[mid] < k){
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr,s, mid-1, k);
    }
}

int main()
{
    int arr[6] = {2,4,6,10,14,18};
    int size = 6;
    int key = 18;

    bool ans =  binarySearch(arr, 0, 5, key);
    if(ans){
        cout<<"Element present"<<endl;
    }
    else{
        cout<<"Element not present"<<endl;
    }

    return 0;
}
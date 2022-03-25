#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[], int size){
    cout<<"size of array is  "<< size <<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

bool linearsearch(int arr[], int size, int key){
    
    printarr(arr, size);
    // base case:
    if(size == 0)
        return false;
    
    if(arr[0] == key){
        return true;
    }
    else{
        bool remainingpart = linearsearch(arr+1, size-1, key);
        return remainingpart;
    }
}

int main()
{   
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    
    int key = 2;
    
    bool ans = linearsearch(arr,size,key);
    if(ans){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}
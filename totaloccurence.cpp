#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){

        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        }
        else if(key > arr[mid]){    // right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]){       //
            e = mid - 1;    //left me jao
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){

        if(arr[mid] == key){
            ans = mid;
            s = mid+1;
        }
        else if(key > arr[mid]){    // right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]){       //
            e = mid - 1;    //left me jao
        }
        mid = s + (e-s)/2;
    }
    return ans;
}


int main()
{
    int arr[5] = {1, 2, 3, 3, 5};

    cout<<"First occurence of 3 is at Index "<< firstOcc(arr, 5, 3)<<endl;
    cout<<"Last occurence of 3 is at Index "<< lastOcc(arr, 5, 3)<<endl;

    int totalOcc = (lastOcc(arr,5,3) - firstOcc(arr,5,3)) + 1;
    cout<<"Total No of occurences is "<<totalOcc<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int size){
    // base case:
    if(size == 0 || size == 1)
        return true;
    
    if(arr[0]>arr[1]){  //not sorted
        return false;
    }
    else{
        bool ans = isSorted(arr+1, size-1);
        return ans;
    }   
    
}

int main()
{
    int arr[6] = {2,4,6,9,11,13};
    int size = 6;

    bool ans = isSorted(arr, size);
    cout<<ans<<endl;
    cout<<endl;
    int arrr[6] = {2,4,4,3,1,13};
    int sizee = 6;

    bool answ = isSorted(arrr, sizee);
    cout<<answ;
    return 0;
}
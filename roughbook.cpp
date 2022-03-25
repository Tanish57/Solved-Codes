#include<bits/stdc++.h>
using namespace std;



void printArray(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> arr = {2, -3, 3, 3, -2};
    int s = 0;
    vector<int> ans = pairSum(arr, s);

    return 0;
}
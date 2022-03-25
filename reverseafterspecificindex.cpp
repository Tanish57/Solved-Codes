#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
    int s = m+1, e = arr.size()-1;
    while(s<=e){
        swap(arr[s], arr[e]);
        s++; e--;
    }
}

void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    reverseArray(v, 3);
    print(v);
    return 0;
}
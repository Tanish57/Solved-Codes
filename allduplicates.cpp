#include<bits/stdc++.h>
using namespace std;

void duplicates(int arr[], int size){
    int twice[100];
    for(int i=0;i<size;i++){
        for(int j=1;i<size;j++){
            if(arr[i] == arr[j]){
                twice[i] = arr[i];
            }
        }
    }
    for(int i = 0; i<size; i++){
        cout<<twice[i];
    }
}

int main()
{
    int arr[] = {4,3,2,7,8,2,3,1};
    duplicates(arr,8);

    return 0;
}


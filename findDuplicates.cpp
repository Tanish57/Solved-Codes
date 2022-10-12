#include<bits/stdc++.h>
using namespace std;

void findDuplicates(int arr[], int size){
  
  for(int i = 0; i<size; i++){
    arr[arr[i] % size] = arr[arr[i] % size] + size;
  }
  
  for(int i = 0; i<size; i++){
    if(arr[i] > size * 2)
      cout<<i<<endl; 
  }
 }

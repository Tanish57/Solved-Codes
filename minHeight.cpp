#include<bits/stdc++.h>
using namespace std;

void minHeight(int arr[], int n, int k){
  sort(arr, arr+n);
  
  int minHeight = arr[0];
  int maxHeight = arr[n-1];
  int ans = maxHeight - minHeight;
  
  for(int i = 0; i<n; i++){
    if(arr[i] - k < 0)
      continue;
    
    minHeight = min(arr[0] + k, arr[i] - k);
    maxHeight = max(arr[i-1] + k, arr[n-1] - k);
    ans = min(ans, maxHeight - minHeight);
    
  }
  cout<<ans<<endl;
}

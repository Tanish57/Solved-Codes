void maxSum(int arr[], int n){
  int start = 0, end = 0, s = 0, max_so_far = INT_MIN, max_ending_here = 0;
  
  for(int i = 0; i<n; i++){
    max_ending_here += arr[i];
    
    if(max_so_far < max_ending_here){
      max_so_far = max_ending_here;
      start = s;
      end = i;
    }
    
    if(max_ending_here < 0){
      max_ending_here = 0;
      s = i+1;
    }
  }
  
  cout<<"Maximum Consecutive Sum is : "<<max_so_far<<endl;
  cout<<"Starting at index "<<start<<endl;
  cout<<"Ending at index "<<end<endl;
}

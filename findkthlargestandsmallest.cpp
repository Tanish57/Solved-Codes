void kthSmallest(int arr[], int n, int k){
  priority_queue<int> pq; //maxHeap
  
  for(int i = 0; i<n; i++){
    pq.push(arr[i]);
    if(pq.size() > k){
      pq.pop();
    }
  }
  cout<<pq.top()<<endl;
}

void kthLargest(int arr[], int n, int k){
  priority_queue<int, vector<int>, greater<int> > pq;   //minHeap
  
  for(int i = 0; i<k; i++){
    pq.push(arr[i]);
  }
  
  for(int i = k; i<n; i++){
    if(arr[i] > pq.top()){
      pq.pop();
      pq.push(arr[i]);
    }
  }
  cout<<pq.top()<<endl;
}

class Node{
  public:
  int data;
  Node* next;
  
  Node(int d){
    this->data = d;
    this->next = NULL;
  }
  
  ~Node(){
    int value = this->data;
    if(this->next != NULL){
      delete next;
      next = NULL;
    }
    cout<<"deleted node with data "<<value<<endl;
  }
};

void insertNode(Node* &tail, int element, int d){
  if(tail == NULL){
    Node* newNode = new Node(d);
    tail = newNode;
    newNode -> next = newNode;
  }
  else{
    Node* curr = tail;
    while(curr->data != element){
      curr = curr->next;
    }
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
  }
}

void deleteNode(Node* &tail, int value){
  if(tail == NULL){
    cour<<"Empty List"<<endl;
    return ;
  }
  else{
    Node* prev = tail;
    Node* curr = tail->next;
    while(curr->data != value){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    if(curr == tail){
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

void print(Node* &tail){
  Node* temp = tail;
  do{
    cout<<tail->data<<" ";
    tail = tail->next;
  } while(tail != temp);
  cout<<endl;
}

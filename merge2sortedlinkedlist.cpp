#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this->data;
        // if(this->next != NULL){
            // delete this->next;
            this->next = NULL;
        // }
        cout<<"Freed memory for node with value "<<value<<endl;
    }
};

void insertAtHead(Node* &head,Node* &tail, int data){

    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        //create a new node:
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
            //create a new node:
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = temp;

    }
}

void insertAtPos(Node* &head, Node* &tail, int position, int data){

    // insert at start
    if(position == 1){
        insertAtHead(head,tail, data);
        return;
    }
    Node*temp = head;
    int cnt = 1;    //we are at first node in starting
    
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    // as we are out of the loop we are at the (n-1)th node

    // inserting at last position:
    if(temp -> next == NULL){
        insertAtTail(head,tail, data);
        return;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head, Node* &tail){

    // deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        // free memory of start node
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        // handling deleting the last node case
        if(curr->next == NULL) {
			tail = prev;
            prev -> next = NULL;
            curr -> next = NULL;
            delete curr;
            return;
		}
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


Node* solve(Node* first, Node* second){
    
    //if only one element present in first list:
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    
    
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL){
        
        if((curr2 -> data >= curr1 -> data) && 
          (curr2 -> data <= next1 -> data)){
            // add node between first list
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{  //does not lie in the range
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1 -> next;
            
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node* sortTwoLists(Node* first, Node* second)
{
    //if first list is empty return second list
    if(first == NULL)
        return second;
    //if second list is empty return first list
    if(second == NULL)
        return first;
   	
    if(first -> data <= second -> data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}

int main()
{
    Node* first = new Node(1);
    Node* head1 = first;
    Node* tail1 = first;
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 5);

    Node* second = new Node(2);
    Node* head2 = second;
    Node* tail2 = second;
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 5);

    print(head1);
    print(head2);

    Node* merged = sortTwoLists(head1, head2);
    print(merged);
    return 0;
}
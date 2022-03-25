#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    //destructor to manually free memory allocated dynamically to the linked list nodes
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for node with data "<<value<<endl;
    }
};

//traversing a linked list
void print(Node* head){
    
    Node* temp = head;
    while(temp != NULL){
        cout<< temp ->data << " ";
        temp = temp->next;
    }cout<<endl;
}

void printReverse(Node* tail){

    Node* temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }cout<<endl;
}

//gives length of the linked list
int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){

    // empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){

    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }

    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;    
}

void insertAtPos(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head,tail, data);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        insertAtTail(head,tail, data);
        return;
    }

    //creating a node for d
    Node* nodetoinsert = new Node(data);
    nodetoinsert -> next = temp->next;
    temp->next->prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert ->prev = temp;
}

void deleteNode(int position, Node* &head, Node* &tail){
    // deleting first or start node:
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
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
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
int main()
{
    // inserting without giving any head or node initially
    //  inserting in an empty linked list
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head,tail, 11);
    print(head);
    insertAtHead(head,tail, 13);
    print(head);
    insertAtHead(head,tail, 8);
    print(head);
    cout<<"head->" <<head->data<<endl;
    cout<<"Tail->"<<tail->data<<endl;
    insertAtTail(head, tail, 15);
    print(head);
    cout<<"Tail->"<<tail->data<<endl;
    insertAtPos(head,tail, 4,100);
    insertAtPos(head,tail, 1,101);
    insertAtPos(head,tail, 7,102);
    print(head);
    cout<<"Head->"<<head->data<<endl;
    cout<<"Tail->"<<tail->data<<endl;

    deleteNode(7, head, tail);
    print(head);
    cout<<"Head->"<<head->data<<endl;
    cout<<"Tail->"<<tail->data<<endl;
    printReverse(tail);
    return 0;
}
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
        if(this->next != NULL){
            delete this->next;
            this->next = NULL;
        }
        cout<<"freed node with value "<<value<<endl;
    }
};

void insertAtHead(Node* &head, Node* & tail, int data){
    if(head == NULL){
        Node* temp  = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail ->next = temp;
        tail = temp;
    }
}


void deletenode(int position, Node* &head, Node* &tail){
    if(position == 1){
        Node* temp = head;
        head = head -> next ;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt != position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        //handling case for last node:
        if(curr->next = NULL){
            tail = prev;
            prev -> next = NULL;
            curr -> next = NULL;
            delete curr;
            return;
        }
        prev -> next = curr;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* head){
    
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp =  temp -> next;
    }cout<<endl;
}

Node* reversekNodes(Node* &head, int k){
    
    //base case:
    if(head == NULL)
        return NULL;
    
    //step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step 2: recursion will handle
    if(next != NULL){
        head ->next = reversekNodes(next, k);
    }

    //step 3: return head of reversed list:
    return prev;
}



int main()
{
    Node* newnode = new Node(1);
    Node* head = newnode;
    Node* tail = newnode;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);

    
    print(head);
    Node* nodeee = reversekNodes(head, 2);
    print(nodeee);
    return 0;
}
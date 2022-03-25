#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int data){
        this -> data = data;
        this ->next = NULL;
    }

    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory freed fo node with data "<<value<<endl; 
    }
};

void insertAtHead(node* &head, node* &tail, int data){

    if(head == NULL){
        node* temp = new node(data);
        temp = head;
        tail = temp;
    }
    else{
        node* temp = new node(data);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(node* &head, node* &tail, int data){
    if(tail == NULL){
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(data);
        tail ->next = temp;
        tail = temp;
    }
}

void deleteNode(int position, node* &head, node* &tail){
    if(position == 1){
        node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt != position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // handling deleting the last node case
        if(curr->next == NULL){
            tail = prev;
            prev -> next = NULL;
            curr ->next = NULL;
            delete curr;
            return;
        }
        prev->next = curr -> next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

node* reverselist(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void reverse(node* &head, node* curr, node* prev){
    
    //base case:
    if(curr == NULL){
        head = prev;
        return;
    }
    
    node *forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;
    
}

node* reverseLinkedList(node *head) 
{
    node *curr = head;
    node *prev = NULL;
    reverse(head, curr, prev);
    return head;
}

node* reverse1(node* head){
    //base case:
    if(head == NULL || head -> next == NULL){
        return head;
    }

    node* newhead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return newhead;
}


int main()
{
    node* node1 = new node(5);
    node* head = node1;
    node* tail = node1;

    insertAtTail(head, tail,7);
    insertAtTail(head, tail,9);
    insertAtTail(head,tail,11);
    insertAtHead(head,tail,3);
    print(head);

    // node* newhead = reverselist(head);
    // print(newhead);

    node* newwhead = reverseLinkedList(head);
    print(newwhead);
    return 0;
}
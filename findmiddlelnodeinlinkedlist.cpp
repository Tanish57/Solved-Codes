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
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory freed for node with value "<<value<<endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
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

void deleteNode(int position, Node* &head, Node* &tail){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt != position){
            prev = curr;
            curr =  curr->next;
            cnt++;
        }
        //handling deleting the last node case:
        if(curr->next == NULL){
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

int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    // Write your code here
    int len = getLength(head);
    int ans = (len/2);
    
    Node* temp = head;
    int cnt = 0;
    while(cnt < ans){
        temp = temp-> next;
        cnt++;
    }
    return temp;
}

//optimized approach:
Node* getMiddle(Node* head){
    
    if(head == NULL || head->next == NULL)
        return head;
    
    //2 nodes
    if(head->next->next == NULL)
        return head->next;

    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL){
        fast = fast ->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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

    Node* middle = getMiddle(head);
    cout<<middle->data<<endl;
    return 0;
}
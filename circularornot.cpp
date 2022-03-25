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
        cout<<"Freed memory for node with value "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int data){

    //empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        // assuming that the element is present in the list

        Node* curr = tail;
        
        while(curr->data != element){
            curr = curr->next;
        }
        //element found -> curr is representing element wala node
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr->next = temp;
    }

}

void print(Node* tail){

    Node* temp = tail;
    
    if(tail == NULL){
        cout<<"Empty list"<<endl;
        return;
    }

    do{
        cout<< tail -> data<<" ";
        tail = tail -> next;
    } while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout << "List is empty, please check again"<<endl;
        return;
    }
    else{
        //non-empty

        //assuming that the value you passed is present in the linked list
        Node* prev = tail;
        Node* curr = prev -> next;
        
        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        // 1 node linked list:
        if(curr = prev){
            tail = NULL;
        }
        // >=2 node linked list
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

bool isCircularlist(Node* head){

    if(head == NULL){
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }
    return false;
}

map<Node*, bool> vis;
bool flag = 0;

void isCircular(Node* head){
    
    if(head == NULL){
        flag = 0;
        return;
    }
    //mark the incoming node as visited if not visited yet
    if(!vis[head]){
        vis[head] = true;
        isCircular(head->next);
    }
    
    //if a visited node is found update the flag value to 1:
    else{
        flag = 1;
        return;
    }
}

int main()
{
    Node* tail = NULL;
    insertNode(tail, 1, 1);    
    insertNode(tail, 1, 2);    
    insertNode(tail, 2, 3);    
    insertNode(tail, 3, 4);    
    print(tail);
    if(isCircularlist(tail)){
        cout<<"It is a circular linked list"<<endl;
    }
    else{
        cout<<"Not a circular linked list";
    }

    isCircular(tail);

    if(flag){
        cout<<"Loop detected"<<endl;;
    }
    else{
        cout<<"No loop detected"<<endl;    
    }
    return 0;
}
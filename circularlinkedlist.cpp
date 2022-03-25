#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"freed memory for node with data "<<value<<endl;
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

int main()
{
    Node* tail = NULL;
    //insertion in empty list
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
    insertNode(tail, 7, 8);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    return 0;
}
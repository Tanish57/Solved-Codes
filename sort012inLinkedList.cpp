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

Node* sortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head;
    while(temp != NULL){
        
        if(temp -> data == 0){
            zeroCount++;
        }
        else if(temp -> data == 1){
            oneCount++;
        }
        else if(temp -> data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }
    
    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }
return head;
}

void InsertAtTail(Node* &tail, Node* curr){
    
    tail -> next = curr;
    tail = curr;
}

Node* sortList1(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    //create seperate list 0s, 1s and 2s
    while(curr != NULL){
        
        int value = curr -> data;
        
        if(value==0){
            InsertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            InsertAtTail(oneTail, curr);
        }
        else if(value == 2){
            InsertAtTail(twoTail, curr);
        }
        curr =  curr -> next;
    }
    
    //merge these 3 sublists
    // 1 ki list non empty hai
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    // 1 ki list empty hai
    else{
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    // merge complete

    //setup head:
    head = zeroHead -> next;

    //delete dummy nodes;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
   	return head;
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    print(head);

    Node* newHead = sortList1(head);
    print(newHead);
    return 0;
}
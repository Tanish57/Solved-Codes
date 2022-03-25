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

Node * uniqueSortedList(Node * head) {
    //empty list:
    if(head == NULL){
        return NULL;
    }
    
    //non empty list:
    Node* curr = head;	
    
    while(curr != NULL){
        if((curr -> next != NULL) && curr -> data == curr -> next -> data){
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else{	//not equal:
            curr = curr -> next;
        }
    }
    return head;
}

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){

        Node* temp = curr -> next;
        prev = curr;

        while(temp != NULL){
            if(curr->data == temp -> data){
                Node* next_next = temp -> next;
                Node* toDelete = temp;
                toDelete -> next = NULL;
                temp  = next_next;
                delete toDelete;
                prev -> next = next_next;
            }
            else{
                temp = temp->next;
                prev = prev->next;
            }
        }
        curr = curr -> next;
    }
    
    return head;
}

Node *removeDuplicatesusingmap(Node *head)
{	
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    map<int, bool> visited;
    
    while(curr != NULL){
        if(!visited[curr->data]){
            visited[curr->data] = true;
            prev = curr;
            curr = curr -> next;
        }
        else{
            prev -> next = curr -> next;
            Node* todelete = curr;
            delete todelete;
        }
        curr = prev -> next;
    }
    return head;
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    print(head);
    // Node* uniquehead = uniqueSortedList(head);
    Node* nehead =  removeDuplicatesusingmap(head);
    print(nehead);
    return 0;
}
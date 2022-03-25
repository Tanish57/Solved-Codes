#include<iostream>
#include<map>
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
/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* floydDetectLoop(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(slow != NULL && fast != NULL){
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    //step 1: find point of intersection of fast and slow
    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL){
        return NULL;
    }
    Node* slow = head;
    //step 2:
    while(slow != intersection){
        slow = slow ->next;
        intersection = intersection -> next;
    }

    return slow;
}

Node *removeLoop(Node *head)
{
    if(head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
	if(startOfLoop == NULL){
        return head;
    }
    Node* temp = startOfLoop;
    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp->next = NULL;
    return head;
}
int main()
{
     //created a new node
    Node* node1 = new Node(10);
    // cout << node1 -> data << endl; 
    // cout << node1 -> next <<endl;

    //head pointed to node1:
    Node* head = node1;
    // tail pointed to node1:
    Node* tail = node1;
    print(head);
    
    insertAtHead(head,tail,12);
    insertAtHead(head,tail,15);
    print(head);

    insertAtTail(head,tail,17);
    print(head);

    insertAtPos(head,tail, 3, 19);
    insertAtPos(head,tail, 1, 5);
    insertAtPos(head,tail, 7, 25);
    print(head);
    if(floydDetectLoop(tail) != NULL){
        cout<<"Loop detected"<<endl;
    }
    else{
        cout<<"Loop not detected \n";
    }

     tail->next = head->next;

    if(floydDetectLoop(tail)){
        cout<<"Loop detected"<<endl;
    }
    else{
        cout<<"Loop not detected \n";
    }

    Node* loop = getStartingNode(head);
    cout<<"Cycle starting at "<< loop -> data <<endl;

    removeLoop(head);

    print(head);
    return 0;
}
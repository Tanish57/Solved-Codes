#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // if(this->next != NULL){
        // delete this->next;
        this->next = NULL;
        // }
        cout << "Freed memory for node with value " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        // create a new node:
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        // create a new node:
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPos(Node *&head, Node *&tail, int position, int data)
{

    // insert at start
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node *temp = head;
    int cnt = 1; // we are at first node in starting

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // as we are out of the loop we are at the (n-1)th node

    // inserting at last position:
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head, Node *&tail)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // free memory of start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // handling deleting the last node case
        if (curr->next == NULL)
        {
            tail = prev;
            prev->next = NULL;
            curr->next = NULL;
            delete curr;
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool checkPalindrome(vector<int> arr)
{
    int size = arr.size();

    int s = 0;
    int e = size - 1;

    while (s <= e)
    {
        if (arr[s] != arr[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

// Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    // step1 : create vector:
    vector<int> arr;

    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
}

//optimized approach to check Palindrome
Node* getMid(Node* head){
        
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
  
//Function to check whether the list is palindrome.
bool issPalindrome(Node *head){
    if(head -> next == NULL){
        return true;
    }
        
    //step1 : find mid;
    Node* middle = getMid(head);
        
    //step2 : reverse list after middle;
    Node* temp = middle -> next;
    middle -> next = reverse(temp);
        
    //step3: compare both halves:
    Node* head1 = head;
    Node* head2 = middle -> next;
        
    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            return false;
        }
        else{
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }
    //step4 : repeat step2:
    temp = middle -> next;
    middle -> next = reverse(temp);
        
    return true;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    print(head);

    if(issPalindrome(head)){
        cout<<"Linked list is palindrome"<<endl;
    }
    else{
        cout<<"Linked list is not palindrome";
    }
    return 0;
}
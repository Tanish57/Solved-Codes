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

// void insertAtTail(Node *&head, Node *&tail, int data)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(data);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         // create a new node:
//         Node *temp = new Node(data);
//         tail->next = temp;
//         tail = temp;
//     }
// }


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

Node *reverse(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val)
{

    Node *temp = new Node(val);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *first, Node *second)
{
    int carry = 0;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

// Function to add two numbers represented by linked list.
Node *addTwoLists(Node *first, Node *second)
{
    // step 1 -  reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step2 - add 2 LL
    Node *ans = add(first, second);

    // step 3
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node* first = new Node(1);
    Node* head1 = first;
    Node* tail1 = first;
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 5);

    Node* second = new Node(2);
    Node* head2 = second;
    Node* tail2 = second;
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 5);

    print(head1);
    print(head2);

    Node* sum = addTwoLists(head1, head2);
    cout<<"Sum is: "<<endl;
    print(sum);
    return 0;
}
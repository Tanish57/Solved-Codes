#include<bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    //base case:
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d> root->data){
        //right part me insert krna hai
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //left me insert krna hai
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }

}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);   //seperator for level 0

    while(!q.empty()){
        Node* temp = q.front();
        
        q.pop();

        if(temp == NULL){ // purana level complete traverse ho chuka hai matlab uske saare childs me queue mein daal chuka hu
            cout<<endl;
            if(!q.empty()) { // queue still has some child nodes left:
                q.push(NULL);   // kyoki bache huye child ko bhi to print karna hai enter k saath
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

void inOrder(Node* root){
    //base case:
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node* root){
    //base case:
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root){
    //base case:
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;

    cout<<"Enter Data to create BST"<<endl;
    takeInput(root);
    cout<<"OUTPUT:"<<endl;
    levelOrderTraversal(root);
    cout<<"InOrder Traversal: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"preOrder Traversal: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal: "<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}

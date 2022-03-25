#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

    cout << "Enter the data :" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);   //seperator for level 0

    while(!q.empty()){
        node* temp = q.front();
        
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

void inorder(node* root, int &count){
    // base condition:
    if(root == NULL){
        return;
    }
    
    inorder(root->left, count);
    
    // leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    
    inorder(root->right, count);
}
int noOfLeafNodes(node* root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter Left node for : "<< temp->data <<endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<< temp->data <<endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}
int main()
{
    node* root = NULL;

    buildFromLevelOrder(root);
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);
    cout<<"No of leaf nodes are: "<< noOfLeafNodes(root) << endl;
    return 0;
}
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

bool isIdentical(node *r1, node *r2)
{
    // base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
        
    if(r1 == NULL && r2 != NULL){
        return false;
    }
        
    if(r1 != NULL && r2 == NULL){
        return false;
    }
        
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
        
    bool value = r1->data == r2->data;
        
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    node* root1 = NULL;
    node* root2 = NULL;
    cout<<"Enter values for tree 1:"<<endl;
    buildFromLevelOrder(root1);
    cout<<"Enter value for tree 2: "<<endl;
    buildFromLevelOrder(root2);

    if(isIdentical(root1, root2)){
        cout<<"The two trees are identical"<<endl;
    }
    else{
        cout<<"The two trees are not identical"<<endl;
    }
    
    return 0;
}
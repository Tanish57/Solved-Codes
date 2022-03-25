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

pair<bool, int> isSumTreeFast(node* root){
    //base case:
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
        
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
        
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);
        
    bool left = leftAns.first;
    bool right = rightAns.first;
        
    bool condn = root->data == leftAns.second + rightAns.second;
        
    pair<bool, int> ans;
        
    if(left && right && condn){
        ans.first = true;
        ans.second = 2*root->data ;
    }
    else{
        ans.first = false;
    }
    return ans;
}
    
bool isSumTree(node* root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    node* root = NULL;

    buildFromLevelOrder(root);
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);
    if(isSumTree(root)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
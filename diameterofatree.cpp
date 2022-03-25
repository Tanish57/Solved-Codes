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

// approach 1, with time complexity = O(n^2):
// int height(node* node){
//     // base case:
//     if(node == NULL){
//         return 0;
//     }
        
//     int left = height(node -> left);
//     int right = height(node -> right);
        
//     int ans = max(left, right) + 1;
//     return ans;
// }

// int diameter(node* root) {
//     // base case
//     if(root == NULL){
//         return 0;
//     }
    
//     int op1 = diameter(root->left);
//     int op2 = diameter(root->right);
//     int op3 = height(root->left) + height(root->right) + 1;
    
//     int ans = max(op1, max(op2, op3));
//     return ans;
// }

// optimized approach 2: TC : O(n)
pair<int,int> diameterFast(node* root){
    // base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
    }
    
    int diameter(node* root) {
        return diameterFast(root).first;
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
    cout<<"Diameter of binary tree is: "<< diameter(root) << endl;
    return 0;
}
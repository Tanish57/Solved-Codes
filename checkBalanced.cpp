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

// bool isBalanced(node* root)
//     {
//         // base case:
//         if(root == NULL){
//         return true;
//     }
        
//     bool left = isBalanced(root->left);
//     bool right = isBalanced(root->right);
        
//     bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
//     if(left && right && diff){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// approach 2: in TC- O(n)
pair<bool,int> isBalancedFast(node* root){
    // base case:
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
        
    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);
        
    bool leftAns = left.first;
    bool rightAns = right.first;
        
    bool diff = abs(left.second - right.second) <= 1;
        
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
        
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}
    
bool isBalanced(node *root)
{
    return isBalancedFast(root).first;
}

int main()
{
    node* root = NULL;

    buildFromLevelOrder(root);
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);
    cout<<isBalanced(root)<<endl;
    return 0;
}
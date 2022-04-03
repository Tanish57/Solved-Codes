// Recursive Approach:
// bool searchInBST(BinaryTreeNode<int> *root, int x) {
//     // base case
//     if(root == NULL){
//         return false;
//     }
    
//     if(root->data == x){
//         return true;
//     }
    
//     // recursive calls:
//     if(root->data > x)
//         return searchInBST(root->left, x); //left part me
//     else
//         return searchInBST(root->right, x); //right part me
// }

//optimized approach using iteration    
bool searchInBST(Node* root , int x) {
    Node *temp = root;
    
    while(temp != NULL){
        if(temp->data == x)
            return true;
        if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

// Node* LCAinaBST(Node* root, Node* P, Node* Q)
// {
// 	// base case
//     if(root == NULL){
//         return NULL;
//     }
    
//     if(root->data < P->data && root->data < Q->data)
//         return LCAinaBST(root->right, P, Q);
    
//     if(root->data > P->data && root->data > Q->data)
//         return LCAinaBST(root->left, P, Q);
    
//     return root;
// }


// optimized approach with SC -> O(1):
Node* LCAinaBST(Node* root, Node* P, Node* Q)
{
    while(root != NULL){
        if(root->data < P->data && root->data < Q->data)
            root = root->right;
        
        else if(root->data > P->data && root->data > Q->data)
            root = root->left;
        else{
            return root;
        }
    }
}

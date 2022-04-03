//find minimum element in a binary search tree:

int findMinBST(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

//Find maximum element in a binary search tree:
int findMaxBST(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

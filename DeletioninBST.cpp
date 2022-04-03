Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

//Find maximum element in a binary search tree:
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    //base case:
    if(root == NULL)
        return root;
    
    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        
        // left child
        if(root -> left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root -> left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root ->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root-> data = mini;
            root ->right = deleteFromBST(root->right , mini);
            return root;
        }
    }
    else if(root->data > val){
        root -> left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

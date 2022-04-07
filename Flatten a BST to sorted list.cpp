void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* flatten(Node* root)
{
    vector<int> inorderVal;
    //store inOrder -> sorted values:
    inorder(root, inorderVal);
    int n = inorderVal.size();
    Node* newRoot = new Node(inorderVal[0]);
    
    Node* curr = newRoot;
    
    //2nd step
    for(int i=1; i < n; i++){
        Node* temp = new Node(inorderVal[i]);
        
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
    // 3rd step:
    curr -> left = NULL;
    curr -> right = NULL;
    
    return newRoot;
}

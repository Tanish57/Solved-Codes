void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> inorderVal){
    // base case:
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inorderVal[mid]);
    root->left = inorderToBST(s, mid-1, inorderVal);
    root->right = inorderToBST(mid+1, e, inorderVal);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderVal;
    //store inOrder -> sorted values:
    inorder(root, inorderVal);
    int n = inorderVal.size();
    
    return inorderToBST(0, n-1, inorderVal);
}

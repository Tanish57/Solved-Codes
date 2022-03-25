Node* solve(Node* root, int &k, int node){
    // base case:
    if( root == NULL){
        return NULL;
    }
    
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    //wapas
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if((rightAns != NULL && leftAns == NULL)){
        k--;
        if(k<=0){
            k = INT_MAX;    //INT_MAX to lock the ans i.e. the current root, so however many times we pass this element to upper nodes, the current root only gets passed
            return root;
        }
        return rightAns;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

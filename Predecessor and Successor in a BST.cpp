pair<int,int> predecessorSuccessor(Node* root, int key)
{
    // find key:
    Node* temp = root;
    int pred = -1;
    int succ = -1;
    
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }
    
    // pred and succ
    // pred
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    //succ
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    pair<int,int> ans = make_pair(pred,succ);
    return ans;
}

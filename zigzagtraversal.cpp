#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // seperator for level 0

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        { // purana level complete traverse ho chuka hai matlab uske saare childs me queue mein daal chuka hu
            cout << endl;
            if (!q.empty())
            {                 // queue still has some child nodes left:
                q.push(NULL); // kyoki bache huye child ko bhi to print karna hai enter k saath
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter Left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);
        // Level process
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        // direction change:
        leftToRight = !leftToRight;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    node* root = NULL;

    buildFromLevelOrder(root);
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);
    vector<int> zigzag = zigZagTraversal(root);
    for(int i = 0; i<zigzag.size(); i++){
        cout<<zigzag[i]<<" ";
    }cout<<endl;
    return 0;
}
// 1 3 2 4 5 6 7
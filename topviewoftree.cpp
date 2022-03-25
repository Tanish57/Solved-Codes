#include <bits/stdc++.h>
using namespace std;

// Function to return a list of nodes visible from the top view
// from left to right in Binary Tree.
vector<int> topView(Node *root){
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> topNode;      // mapping of horizontal distance to node/root->data
    queue<pair<Node *, int>> q; // int representing horizontal distance

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // maintain one to one mapping
        // if one value is present for a horizont distance, then do nothing
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{

    return 0;
}
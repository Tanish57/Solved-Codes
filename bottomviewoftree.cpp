#include <bits/stdc++.h>
using namespace std;

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> topNode;      // mapping of horizontal distance to node/root->data
    queue<pair<Node *, int>> q; // int representing horizontal distance

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
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
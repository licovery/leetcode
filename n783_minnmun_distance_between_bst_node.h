#ifndef N783_MINNMUN_DISTANCE_BETWEEN_BST_NODE_H
#define N783_MINNMUN_DISTANCE_BETWEEN_BST_NODE_H

#include <bits/stdc++.h>
using namespace std;

namespace n783
{

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        int minDistance = INT_MAX;
        dfs(root, minDistance);
        return minDistance;
    }

    void dfs(TreeNode *root, int &minDistance)
    {
        if (root == nullptr) return;
        dfs(root->left, minDistance);
        _twoNode.push(root->val);
        if (_twoNode.size() == 2)
        {
            minDistance = min(minDistance, _twoNode.back() - _twoNode.front());
            _twoNode.pop();
        }
        dfs(root->right, minDistance);
    }
private:
    queue<int> _twoNode;
};

}

#endif // N783_MINNMUN_DISTANCE_BETWEEN_BST_NODE_H

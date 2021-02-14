#ifndef N673_AVERAGE_OF_LEVELS_IN_BINARY_TREE_H
#define N673_AVERAGE_OF_LEVELS_IN_BINARY_TREE_H

#include <bits/stdc++.h>
using namespace std;

namespace n673
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;
        if (!root)
        {
            return result;
        }
        unvisited.push(root);
        while (unvisited.size() != 0)
        {
            int curLevelNodeNum = unvisited.size();
            double curLevelSum = 0;
            for (int nodeLoop = 0; nodeLoop < curLevelNodeNum; nodeLoop++)
            {
                auto node = unvisited.front();
                curLevelSum += node->val;
                if (node->left)
                {
                    unvisited.push(node->left);
                }
                if (node->right)
                {
                    unvisited.push(node->right);
                }
                unvisited.pop();
            }
            double curLevelAvg = curLevelSum / static_cast<double>(curLevelNodeNum);
        }

    }

    void bfs(TreeNode *root)
    {


    }
private:
    queue<TreeNode *> unvisited;
};

}

#endif // N673_AVERAGE_OF_LEVELS_IN_BINARY_TREE_H

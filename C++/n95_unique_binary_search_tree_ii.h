#ifndef N95_UNIQUE_BINARY_SEARCH_TREE_II_H
#define N95_UNIQUE_BINARY_SEARCH_TREE_II_H

#include "leetcode_common.h"

namespace n95
{

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n <= 0)
        {
            return vector<TreeNode *> ();
        }
        return genTree(1, n);

    }
private:
    // 这里采用了归并排序的思想，分治法。先递归，再合并
    vector<TreeNode *> genTree(int s, int e)
    {
        vector<TreeNode *> res;
        if (s > e)
        {
            // 此处不能返回res，一定要把空指针加上，空指针指代空树
            res.push_back(nullptr);
        }
        else
        {
            for (int i = s; i <= e; i++)
            {
                vector<TreeNode *> leftTrees = genTree(s, i - 1);
                vector<TreeNode *> rightTrees = genTree(i + 1, e);
                // 先生成子树，再利用子树构建整棵树
                for (auto leftNode : leftTrees)
                {
                    for (auto rightNode : rightTrees)
                    {
                        auto curNode = new TreeNode(i);
                        // 用前面求得的左子树和右子树的根节点（有可能为空）来构建curNode
                        curNode->left = leftNode;
                        curNode->right = rightNode;
                        res.push_back(curNode);
                    }
                }
            }
        }

        return res;
    }
};

}

#endif // N95_UNIQUE_BINARY_SEARCH_TREE_II_H

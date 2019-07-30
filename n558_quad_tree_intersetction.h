#ifndef N558_QUAD_TREE_INTERSETCTION_H
#define N558_QUAD_TREE_INTERSETCTION_H

#include <bits/stdc++.h>
using namespace std;

namespace n558
{

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (!quadTree1 || !quadTree2)
        {
            return nullptr;
        }

        Node *result = nullptr;

        if (quadTree2->isLeaf)
        {
            swap(quadTree1, quadTree2);
        }

        if (quadTree1->isLeaf)
        {
            if (quadTree1->val)
            {
                result = quadTree1;
            }
            else
            {
                result = quadTree2;
            }
        }
        else
        {
            Node *topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node *topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            Node *bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node *bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if (canCombineQuadTree(topLeft, topRight, bottomLeft, bottomRight))
            {
                result = new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);
            }
            else
            {
                result = new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
            }
        }
        return result;
    }

    bool canCombineQuadTree(Node *topLeft, Node *topRight, Node *bottomLeft, Node *bottomRight)
    {
        return topLeft->isLeaf &&
               topRight->isLeaf &&
               bottomLeft->isLeaf &&
               bottomRight->isLeaf &&
               topLeft->val == topRight->val &&
               topRight->val == bottomLeft->val &&
               bottomLeft->val == bottomRight->val;
    }
};

}

#endif // N558_QUAD_TREE_INTERSETCTION_H

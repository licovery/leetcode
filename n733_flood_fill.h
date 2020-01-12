#ifndef N733_FLOOD_FILL_H
#define N733_FLOOD_FILL_H

#include <bits/stdc++.h>
using namespace std;

namespace n733
{

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] != newColor)
        {
            dfs(image, sr, sc, newColor, image[sr][sc]);
        }
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
    {
        if (sr < 0 || sr >= image.size()) return;
        if (sc < 0 || sc >= image[0].size()) return;

        if (image[sr][sc] != oldColor) return;

        image[sr][sc] = newColor;

        dfs(image, sr - 1, sc, newColor, oldColor);
        dfs(image, sr + 1, sc, newColor, oldColor);
        dfs(image, sr, sc - 1, newColor, oldColor);
        dfs(image, sr, sc + 1, newColor, oldColor);
    }
};

}

#endif // N733_FLOOD_FILL_H

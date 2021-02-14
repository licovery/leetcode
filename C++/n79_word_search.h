#ifndef N79_WORD_SEARCH_H
#define N79_WORD_SEARCH_H

#include "leetcode_common.h"

namespace n79
{

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() == 0 || board[0].size() == 0)
        {
            return false;
        }
        // 一个优化的方式是不单独建立visited而是利用原来的board
        // 把访问过的board[row][col]设定为一个特殊字符'\0'，访问完再恢复，也可达到相同的效果。
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, i, j, visited, word, 0) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
private:
    bool dfs(const vector<vector<char>> &board, int row, int col, vector<vector<bool>> &visited, const string &word, int step)
    {
        if (step == word.size())
        {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        {
            return false;
        }

        if (visited[row][col] || board[row][col] != word[step])
        {
            return false;
        }


        visited[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            if (dfs(board, row + direction[i][0], col + direction[i][1], visited, word, step + 1) == true)
            {
                return true;
            }
        }
        visited[row][col] = false;
        return false;
    }
    static constexpr int direction[4][2] =
    {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
};


}

#endif // N79_WORD_SEARCH_H

/*
Print all valid configuration for 'N' queens placement on N*N board.
The configuration of a board should be in 1-D form stored in ans with 2-D form.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int i, int j, int n, vector<vector<int>> &board)
    {
        // checking no queen is present in same row/column
        for (int k = 0; k < n; k++)
        {
            if (board[k][j] || board[i][k])
            {
                return false;
            }
        }

        // checking diagonals
        int curR = i - 1, curC = j - 1;
        while (curR >= 0 && curC >= 0)
        {
            if (board[curR][curC])
            {
                return false;
            }
            curR--;
            curC--;
        }

        curR = i + 1, curC = j + 1;
        while (curR < n && curC < n)
        {
            if (board[curR][curC])
            {
                return false;
            }
            curR++, curC++;
        }

        curR = i + 1, curC = j - 1;
        while (curR < n && curC >= 0)
        {
            if (board[curR][curC])
            {
                return false;
            }
            curR++, curC--;
        }

        curR = i - 1, curC = j + 1;
        while (curC < n && curR >= 0)
        {
            if (board[curR][curC])
            {
                return false;
            }
            curC++, curR--;
        }

        return true;
    }

    void helper(int i, vector<vector<int>> &board, int q, vector<vector<int>> &ans)
    {
        int n = board.size();
        if (q == n)
        {
            vector<int> config;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    config.push_back(board[r][c]);
                }
            }

            ans.push_back(config);
            return;
        }

        if (i >= n)
        {
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(i, col, n, board))
            {
                board[i][col] = 1;
                helper(i + 1, board, q + 1, ans);
                board[i][col] = 0;
            }
        }
    }

    vector<vector<int>> solveNQueens(int n)
    {
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        helper(0, board, 0, ans);
        return ans;
    }
};
/*

*/

#include <bits/stdc++.h>
using namespace std;

// DP: [TC: O(n*n), AS: O(1)]
class Solution
{
public:
    /*
    The intuition behind the dynamic programming approach is that the minimum path sum to reach a position
    (i, j) in the grid can be computed by considering the minimum path sum to reach the positions (i-1, j)
    and (i, j-1).

    This is because the only two possible ways to reach the position (i, j) are either by moving down from
    (i-1, j) or moving right from (i, j-1).

    By computing the minimum path sum to reach each position in the grid, the algorithm can find the minimum
    path sum to reach the bottom-right corner of the grid by simply looking at the last element of the array
    (grid[m-1][n-1]).
    */

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // As for row0 and column0 => There is only one way to reach
        for (int i = 1; i < m; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; j++)
        {
            grid[0][j] += grid[0][j - 1];
        }

        // Table filling
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
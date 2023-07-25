#include <bits/stdc++.h>
using namespace std;

// [TC: O(4^(N*N)), AS: O(N*N)]
// 4 direction choices can be taken at each cell => 4^(N*N)
class Solution
{
public:
    bool isSafe(vector<vector<int>> &mat, int i, int j)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0)
        {
            return false;
        }
        return true;
    }

    bool helper(vector<vector<int>> &mat, int i, int j, string curr, vector<string> &ans)
    {
        int n = mat.size();
        // final destination reached
        if (i == n - 1 && j == n - 1 && isSafe(mat, i, j))
        {
            mat[i][j] = 1;
            ans.push_back(curr);
            return true;
        }

        if (isSafe(mat, i, j))
        {
            mat[i][j] = 0;
            bool c1 = helper(mat, i + 1, j, curr + "D", ans);
            bool c2 = helper(mat, i, j + 1, curr + "R", ans);
            bool c3 = helper(mat, i - 1, j, curr + "U", ans);
            bool c4 = helper(mat, i, j - 1, curr + "L", ans);
            mat[i][j] = 1;

            return c1 || c2 || c3 || c4;
        }

        return false;
    }

    vector<string> ratMaze(vector<vector<int>> &mat)
    {
        vector<string> ans;
        string curr = "";

        helper(mat, 0, 0, curr, ans);
        return ans;
    }
};

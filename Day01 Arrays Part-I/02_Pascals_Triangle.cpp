/*

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(n*m), AS: O(n)]
class Solution1
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }

        vector<vector<int>> Ptriangle;
        Ptriangle.push_back({1});
        Ptriangle.push_back({1, 1});

        for (int i = 2; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = Ptriangle[i - 1][j - 1] + Ptriangle[i - 1][j];
            }
            Ptriangle.push_back(row);
        }

        return Ptriangle;
    }
};

// Using resize vector function [TC: O(n*m), AS: O(n)]
class Solution2
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            ans[i].resize(i + 1, 1);
        }

        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j < ans[i].size() - 1; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        return ans;
    }
};
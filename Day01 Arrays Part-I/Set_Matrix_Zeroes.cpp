/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

#include <bits/stdc++.h>
using namespace std;

// Naive Approach: [ TC: O(n*m), AS: O(n*m) ]
class Solution1
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> v;
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    v.push_back(make_pair(i, j));
                }
            }
        }

        for (auto it = v.begin(); it != v.end(); it++)
        {
            int i0 = it->first, j0 = it->second;
            for (int j = 0; j < c; j++)
            {
                matrix[i0][j] = 0;
            }

            for (int i = 0; i < r; i++)
            {
                matrix[i][j0] = 0;
            }
        }
    }
};

// Better Approach: [ TC: O(n*m), AS: O(n+m) ]
class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> row, col;
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto it = row.begin(); it != row.end(); it++)
        {
            int i0 = *it;
            for (int j = 0; j < c; j++)
            {
                matrix[i0][j] = 0;
            }
        }

        for (auto it = col.begin(); it != col.end(); it++)
        {
            int j0 = *it;
            for (int i = 0; i < r; i++)
            {
                matrix[i][j0] = 0;
            }
        }
    }
};

// Fastest Approach: [ TC: O(n*m), AS: O(1) ]
class Solution3
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        bool row = false, col = false;
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        row = true;
                    }
                    if (j == 0)
                    {
                        col = true;
                    }
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (col)
        {
            for (int i = 0; i < r; i++)
                matrix[i][0] = 0;
        }
        if (row)
        {
            for (int j = 0; j < c; j++)
                matrix[0][j] = 0;
        }
    }
};
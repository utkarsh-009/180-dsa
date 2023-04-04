/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

#include <bits/stdc++.h>
using namespace std;

/*
Naive Approach: [ TC: O(m*n), AS: O(n*m) ]
=> Storing co-ordinated (i,j) in vector of pairs. Then we iterate through vector
to make row and col corresponding to the co-ordinates i,j equal to 0.
*/
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

/*
Better Approach: [ TC: O(m*n), AS: O(n+m) ]
=> Storing rows and columns that need to be made 0 in the set.
Then we iterate through set to make rows and then cols to make it equal to 0
*/
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

/*
Fastest Approach: [ TC: O(m*n), AS: O(1) ]
- Using first row and first column to note down the rows and cols which need to
be made 0, i.e. now if we found 0 in (i,j) of matrix => matrix[i][0] = matrix[0][j] = 0;
- Now iterating through matrix (i = 1 -> m) & (j = 1 -> n) => if(matrix[i][0] == 0 || matrix[0][j] == 0) => matrix[i][j] = 0
- Also if we found any 0 in first row => firstRow will be marked as true as to make it 0 later
- And if we found any 0 in first column => firstCol will be marked as true as to make it 0 later
*/
class Solution3
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        bool firstRow = false, firstCol = false;
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        firstRow = true;
                    }
                    if (j == 0)
                    {
                        firstCol = true;
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
        if (firstCol)
        {
            for (int i = 0; i < r; i++)
                matrix[i][0] = 0;
        }
        if (firstRow)
        {
            for (int j = 0; j < c; j++)
                matrix[0][j] = 0;
        }
    }
};
/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

// M1: Normal Traversal [TC: O(n*n), AS: O(1)]
class Solution1
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size(), c = matrix[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// M2: Using Binary Search for every row [TC: O(n*logn), AS: O(1)]
class Solution2
{
public:
    bool binSearch(vector<int> v, int n, int target)
    {
        int low = 0, high = n - 1, mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (v[mid] == target)
            {
                return true;
            }
            else if (v[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size(), c = matrix[0].size();

        for (int i = 0; i < r; i++)
        {
            if ((binSearch(matrix[i], c, target)))
            {
                return true;
            }
        }
        return false;
    }
};

// M3: Using the property of sorted row-column matrix [TC: O(n+m), AS: O(1)]
class Solution3
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size(), c = matrix[0].size();

        int i = 0, j = c - 1;
        while (i < r && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }

            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
    }
};
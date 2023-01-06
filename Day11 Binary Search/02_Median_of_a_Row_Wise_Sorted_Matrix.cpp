/*
Finding Median of a Row Wise Sorted Matrix

Problem Statement: Given a row wise sorted matrix of size R*C, find the median of the matrix.

    Input:
    R = 3, C = 3
    M = [[1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]]
    Output: 5
    Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force: [ TC: O(R*Clog(R*C)), AS: O(R*C) ]
class Solution1
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        vector<int> v;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                v.push_back(matrix[i][j]);
            }
        }

        sort(v.begin(), v.end());
        int medPos = R * C / 2;

        return ((R * C % 2 != 0) ? v[medPos] : double(v[medPos] + v[medPos - 1]) / 2);
    }
};

// Efficient Binary Search [ TC: O(R*Clog(R*C)), AS: O(1) ]
// Intution: For a number to be median, there should be exactly (n/2) numbers which are less than this number
class Solution2
{
public:

    

    int median(vector<vector<int>> &matrix, int R, int C)
    {

    }
};
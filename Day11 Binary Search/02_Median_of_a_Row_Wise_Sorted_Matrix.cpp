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

// Brute Force: [ TC: O(R*C*log(R*C)), AS: O(R*C) ]
class Solution1
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
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

// Efficient Binary Search [ TC: O(R*log(max-min)*log(C)), AS: O(1) ]
// Intution: For a number to be median, there should be exactly (n/2) numbers which are less than this number
class Solution2
{
public:
    // To find number of elements less than given number
    int upperBound(vector<int> row, int mid)
    {
        int l = 0, h = row.size() - 1;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (row[m] <= mid)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }

        return l;
    }

    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // finding high and low i.e. minimum and maximum element in matrix
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            low = min(matrix[i][0], low);
            high = max(matrix[i][C - 1], high);
        }

        // For a number to be median, there should be exactly (n/2) numbers which are less than this number
        int desired = (R * C + 1) / 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int nums_less_than_mid = 0;

            // counting total number of elements that are less than mid
            for (int i = 0; i < R; i++)
            {
                nums_less_than_mid += upperBound(matrix[i], mid);
            }

            // if elments less than mid are less than desired => low = mid + 1
            if (nums_less_than_mid < desired)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main()
{

    int r = 3;
    int c = 3;
    vector<vector<int>> matrix = {{1, 3, 5},
                                  {2, 6, 9},
                                  {3, 6, 9}};

    Solution1 obj1;
    Solution2 obj2;
    cout << obj2.median(matrix, r, c);
}
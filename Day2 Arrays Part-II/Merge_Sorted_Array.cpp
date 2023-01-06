/*
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]

    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
*/

#include <bits/stdc++.h>
using namespace std;

// M1: Using Sorting Function [TC: O(m*logm), AS: O(1)]
class Solution1
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
        {
            return;
        }

        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }

        sort(nums1.begin(), nums1.end());
    }
};
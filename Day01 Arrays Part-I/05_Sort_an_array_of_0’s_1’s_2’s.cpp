/*

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force: [TC: O(n), AS: O(1)] - 4 for loops (2 traversals)
class Solution1
{
public:
    void sortColors(vector<int> &nums)
    {

        int n0 = 0;
        int n1 = 0;
        int n2 = 0;
        int sz = nums.size();

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == 0)
            {
                n0++;
            }
            if (nums[i] == 1)
            {
                n1++;
            }
            else
            {
                n2++;
            }
        }

        for (int i = 0; i < n0; i++)
        {
            nums[i] = 0;
        }

        for (int i = n0; i < n0 + n1; i++)
        {
            nums[i] = 1;
        }

        for (int i = n0 + n1; i < sz; i++)
        {
            nums[i] = 2;
        }
    }
};

/*
Efficient Approach (Dutch National Flag Algorithm) : [TC: O(n), AS: O(1)] - 1 while loops (Single traversal)
- maintaining three pointers - low = 0, mid = 0, and high = n-1
- While mid <= high, do the following:
    a. If nums[mid] == 0, swap nums[mid] and nums[low], and increment both low and mid pointers.
    b. If nums[mid] == 1, increment mid pointer.
    c. If nums[mid] == 2, swap nums[mid] and nums[high], and decrement the high pointer.
*/
class Solution2
{
public:
    void sortColors(vector<int> &nums)
    {

        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
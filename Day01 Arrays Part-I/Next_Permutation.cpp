/*

Input: nums = [1,3,2]
Output: [2,1,3]

Input: nums = [1,1,5]
Output: [1,5,1]

*/

#include <bits/stdc++.h>
using namespace std;

// Better Approach: [ TC: O(n), AS: O(1) ]
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size(), ind1 = 0, ind2 = 0, indForSort = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                ind1 = i, ind2 = i - 1; // ind1 and ind2 to swap elements
                indForSort = i;         // Storing index to sort subarray in ascending order
                break;
            }
        }

        for (int i = ind1; i < n; i++) // Special Case Ex: [1,3,2] => [2,1,3]  and not [3,1,2]
        {
            if (nums[i] > nums[ind2] && nums[i] < nums[ind1])
            {
                ind1 = i;
            }
        }
        swap(nums[ind1], nums[ind2]);

        sort(nums.begin() + indForSort, nums.end());
    }
};

/*
Intution: Finding the first peak element while traversing from last index (ind1) and swapping it with index (ind2) just after it. This will give us greater permutation.
But to get next greater permutation, we have sort to the elements after the swapped peak elements index.

https://www.youtube.com/watch?v=6qXO72FkqwM

2 3 1 => (i = 1) 3 2 1 (Before Sort) => 3 1 2 (After Sort)
i = 2, nums[i] > nums[i - 1] (1 > 3) => Ignore (ind1 = 0)
i = 1, nums[i] > nums[i - 1] (3 > 2) => True (ind1 = 1)
swap(nums[i], nums[i - 1]) i.e. 2 3 1 => 3 2 1 (ind1 = 1)
sort(nums.begin() + ind1, nums.end()) => 3 1 2

*/
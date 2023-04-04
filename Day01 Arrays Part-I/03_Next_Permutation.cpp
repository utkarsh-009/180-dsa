/*

Input: nums = [1,3,2]
Output: [2,1,3]

Input: nums = [1,1,5]
Output: [1,5,1]

*/

#include <bits/stdc++.h>
using namespace std;

/*
Best Approach: [ TC: O(n), AS: O(1) ]

- Algorithm for Lexicographically greater permutation:
1.) Starting from the end of the given array, find the first index k such that nums[k] < nums[k+1].
2.) If there is no such index k, the array is already in its highest permutation, so reverse the array to
obtain the lowest permutation and return.
3.) Starting from the end of the array, find the first index l such that nums[k] < nums[l].
4.) Swap nums[k] and nums[l].
5.) Reverse the subarray from k+1 to n-1 to get the next lexicographically greater permutation.
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), k, l;

        // Find the largest index k such that nums[k] < nums[k + 1]
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }

        // If no such index exists, reverse nums and return
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the largest index l greater than k such that nums[k] < nums[l]
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }

        // Swap nums[k] and nums[l]
        swap(nums[k], nums[l]);

        // Reverse the subarray nums[k + 1:]
        reverse(nums.begin() + k + 1, nums.end());
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
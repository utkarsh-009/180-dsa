/*
Problem Statement: Given Rotated Sorted Array (nums) and element to be searched (target),
return the index of target if it is in nums, or -1 if it is not in nums.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

// Brute Force: Using Linear Search [TC: O(n), AS: O(1)]
class Solution1
{
public:
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }

        return -1;
    }
};

// Efficient: Using Binary Search [TC: O(logn), AS: O(1)]
class Solution2
{
public:
    /*
    Intution: Using Binary search, we observe that there will exist only two cases:
    - If: mid and low indexes lies in left sorted side (nums[low] <= nums[mid])
    - Else: mid and high indexes lies in right sorted side

    => We can perform binary search depending upon the type of case we encounter
    */
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            // if low and mid are in left-sorted side
            if (nums[low] <= nums[mid])
            {
                // if target lies betweeen nums[low] and nums[mid]
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // if high and mid are in right-sorted side
            else
            {
                // if target lies betweeen nums[mid] and nums[high]
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
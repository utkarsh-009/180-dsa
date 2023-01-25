/*
Problem Statement: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

// Brute Force: Using Auxillary Array [TC: O(m+n), AS: O(m+n)]
class Solution1
{
public:
    double findMed(vector<int> nums)
    {
        int n = nums.size();
        int mid = n / 2;

        return ((n % 2) ? (double)(nums[mid]) : (double)(nums[mid] + nums[mid - 1]) / 2);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nums;
        int p1 = 0, p2 = 0;

        while (p1 < n1 && p2 < n2)
        {
            if (nums1[p1] < nums2[p2])
            {
                nums.push_back(nums1[p1]);
                p1++;
            }
            else
            {
                nums.push_back(nums2[p2]);
                p2++;
            }
        }

        while (p1 < n1)
        {
            nums.push_back(nums1[p1]);
            p1++;
        }

        while (p2 < n2)
        {
            nums.push_back(nums2[p2]);
            p2++;
        }

        return findMed(nums);
    }
};

// Efficient: Using Binary Search [TC: O(log(m+n)), AS: O(1)]
class Solution
{
public:
    double median(vector<int> &arr1, vector<int> &arr2, int m, int n)
    {
        // m should be less than n
        if (m > n)
            return median(arr2, arr1, n, m); // ensuring that binary search happens on minimum size array

        int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
        while (low <= high)
        {
            // cut1 =>
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : arr1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 != 0)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size(), n2 = nums2.size();
        return median(nums1, nums2, n1, n2);
    }
};

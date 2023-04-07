/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

// RECURSIVE: [TC: O(2^n), AS: O(1)] taking both descisions at every step
class Solution1
{
public:
    int max_len = 0;
    void solve(vector<int> &nums, int prev, int curr_len, int idx)
    {
        if (idx >= nums.size())
        {
            max_len = max(max_len, curr_len);
            return;
        }

        // considering the current number in subseq
        if (prev < nums[idx])
        {
            solve(nums, nums[idx], curr_len + 1, idx + 1);
        }

        // not considering the current number in subseq
        solve(nums, prev, curr_len, idx + 1);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        solve(nums, INT_MIN, 0, 0);
        return max_len;
    }
};

// DP (BOTTOM UP): [TC: O(n*n), AS: O(n)]
class Solution2
{
public:
    // NOTE: Either we start subseq from new or we include subseq in the current LIS
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Including the element which will give us Longest Increasing Subsequence
                if (nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// DP (TOP DOWN): [TC: O(n*n), AS: O(n)]
class Solution
{
public:
    // NOTE: Either we start subseq from new or we include subseq in the current LIS
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                // Including the element which will give us Longest Increasing Subsequence
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
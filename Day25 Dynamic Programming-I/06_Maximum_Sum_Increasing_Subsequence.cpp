/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array
such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
*/

// RECURSIVE: [TC: O(2^n), AS: O(n)]
class Solution1
{
public:
    // RECURSION: Considering both cases
    int solve(int arr[], int n, int idx, int prev)
    {
        if (idx >= n)
        {
            return 0;
        }

        // Considering the current number in subsequence
        if (arr[idx] > prev)
        {
            int c1 = arr[idx] + solve(arr, n, idx + 1, arr[idx]);
            int c2 = solve(arr, n, idx + 1, prev);
            return max(c1, c2);
        }

        return solve(arr, n, idx + 1, prev);
    }

    int maxSumIS(int arr[], int n)
    {
        return solve(arr, n, 0, INT_MIN);
    }
};

// DP: [TC: O(n*n), AS: O(n)]
class Solution2
{

public:
    // DP Approach: We store possible msis for every step in dp
    int maxSumIS(int arr[], int n)
    {
        vector<int> dp(n, 0);

        // To store max sum increasing subsequence possible
        int max_sis = 0;

        // To initialise dp with its array element for each index as there can be case where msis will have only one element
        for (int i = 0; i < n; i++)
        {
            dp[i] = arr[i];
        }

        // Compute msis through bottom up manner
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            // Updating msis after calcuating current msis
            max_sis = max(max_sis, dp[i]);
        }

        // returning msis
        return max_sis;
    }
};
/*

We are given N items where each item has some weight and profit associated with it.
We are also given a bag with capacity W, [i.e., the bag can hold at most W weight in it].
The target is to put the items into the bag such that the sum of profits associated with them is the maximum possible.

Input:
N = 3, W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Explanation: There are two items which have weight less than or equal to 4.
If we select the item with weight 4, the possible profit is 1. And if we select the item with weight 1,
the possible profit is 3. So the maximum possible profit is 3.
Note: that we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.
*/

// RECURSIVE:  [TC: O(2^n), AS: O(n)]
class Solution1
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int wt[], int val[], int W, int n, int idx)
    {
        // all weights checked
        if (idx >= n)
        {
            return 0;
        }

        // knapsack limit exceeded
        if (W < 0)
        {
            return 0;
        }

        // if it is weight possible to put weight in knapsack => we have two choices i.e. either we put in or we not
        if (W - wt[idx] >= 0)
        {
            int c1 = val[idx] + solve(wt, val, W - wt[idx], n, idx + 1);
            int c2 = solve(wt, val, W, n, idx + 1);
            return max(c1, c2);
        }
        // else if it is not weight possible to put weight in knapsack => we simply move to next weight
        else
        {
            return solve(wt, val, W, n, idx + 1);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        return solve(wt, val, W, n, 0);
    }
};

// DP: [TC: O(n*w), AS: O(n*w)]
class Solution2
{
public:
    // Function to return max value that can be put in knapsack of capacity W
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // index i-> 0 to n-1
        for (int i = 0; i < n; i++)
        {
            // weights w-> 0 to W
            for (int w = 0; w <= W; w++)
            {
                // if it is weight possible to put weight in knapsack => we have two choices i.e. either we put in or we not
                if (w - wt[i] >= 0)
                {
                    int c1 = val[i] + dp[i][w - wt[i]];
                    int c2 = dp[i][w];
                    dp[i + 1][w] = max(c1, c2);
                }
                // else if it is not weight possible to put weight in knapsack => we simply move to next weight
                else
                {
                    dp[i + 1][w] = dp[i][w];
                }
            }
        }

        return dp[n][W];
    }
};
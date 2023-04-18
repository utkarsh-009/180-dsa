/*
https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Rearranging the cuts to be [3, 5, 1, 4]. for example, will lead to a
scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16)
*/

/*
RECURSIVE APPROACH: The function recursively splits the current segment into two smaller segments, and calculates the
cost of making the cut at each position. It then returns the minimum cost of making the cut in any of the positions.

startStk/endStk-> start/end of current segment
leftIdx/rightIdx-> index of leftmost/rightmost cut of current segment
*/
class Solution1
{
public:
    int solve(int startStk, int endStk, vector<int> &cuts, int leftIdx, int rightIdx)
    {
        if (leftIdx > rightIdx)
        {
            return 0;
        }

        int cost = 1e9;
        for (int i = leftIdx; i <= rightIdx; i++)
        {
            int left_cut = solve(startStk, cuts[i], cuts, leftIdx, i - 1);
            int right_cut = solve(cuts[i], endStk, cuts, i + 1, rightIdx);
            // cost of cut => length of current segment + left_cut cost + right_cut cost
            int curr_cost = (endStk - startStk) + left_cut + right_cut;
            cost = min(cost, curr_cost);
        }

        return cost;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // Sorting is done for proper initial cuts which will disallow invalid cuts for further cuts
        sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};

// DP Approach: [TC: O(N*N*N), AS: O(N*N)]
class Solution2
{
public:
    /*
    DP APPROACH: Storing precomputed subproblems in 2D vector, dp[leftIdx][rightIdx]
    startStk/endStk-> start/end of current segment
    leftIdx/rightIdx-> index of leftmost/rightmost cut of current segment
    */
    int solve(int startStk, int endStk, vector<int> &cuts, int leftIdx, int rightIdx, vector<vector<int>> &dp)
    {
        if (leftIdx > rightIdx)
        {
            return 0;
        }

        if (dp[leftIdx][rightIdx] != -1)
        {
            return dp[leftIdx][rightIdx];
        }

        int cost = 1e9;
        for (int i = leftIdx; i <= rightIdx; i++)
        {
            int left_cut = solve(startStk, cuts[i], cuts, leftIdx, i - 1, dp);
            int right_cut = solve(cuts[i], endStk, cuts, i + 1, rightIdx, dp);
            // cost of cut => length of current segment + left_cut cost + right_cut cost
            int curr_cost = (endStk - startStk) + left_cut + right_cut;
            cost = min(cost, curr_cost);
        }

        return dp[leftIdx][rightIdx] = cost;
    }

    int minCost(int n, vector<int> &cuts)
    {
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        // Sorting is done for proper initial cuts which will disallow invalid cuts for further cuts
        sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts, 0, cuts.size() - 1, dp);
    }
};
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing
a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money
cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

// Recursive: [TC: O(2^n), AS: O(1, excluding rec Stack)]
class Solution {
public:

    long long solve(vector<int>& coins, int amount, int i)
    {
        if(i >= coins.size()) 
        {
            if(amount == 0) {return 0;}
            else {return INT_MAX;}
        }

        if(amount == 0) {return 0;}

        if(coins[i] <= amount)
        {
            return min(1 + solve(coins, amount-coins[i], i), solve(coins, amount, i+1));
        }
        else
        {
            return solve(coins, amount, i+1);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount, 0);
        ans = (ans >= INT_MAX) ? -1 : (int)ans;

        return ans;
    }
};

// DP Approach: [TC: O(n*n), AS: O(n*n)]
class Solution {
public:

    long long solve(vector<int>& coins, int amount, int i, vector<vector<long long>>& dp)
    {
        if(i >= coins.size()) 
        {
            if(amount == 0) {return 0;}
            else {return INT_MAX;}
        }

        if(amount == 0) {return 0;}

        if(dp[i][amount] != -1) {return dp[i][amount];}

        if(coins[i] <= amount)
        {
            return dp[i][amount] = min(1 + solve(coins, amount-coins[i], i, dp), solve(coins, amount, i+1, dp));
        }
        else
        {
            return dp[i][amount] = solve(coins, amount, i+1, dp);
        }
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amount+1, -1));
        int ans = solve(coins, amount, 0, dp);
        ans = (ans >= INT_MAX) ? -1 : (int)ans;

        return ans;
    }
};
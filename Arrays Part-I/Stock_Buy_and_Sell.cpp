/*

Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force: [TC: O(n*n), AS: O(1)]
class Solution1
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = INT_MIN, n = prices.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = prices[j] - prices[i];
                mx = max(mx, diff);
            }
        }

        if (mx < 0)
        {
            mx = 0;
        }

        return mx;
    }
};

// Efficient Approach: [TC: O(n), AS: O(1)]
class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = 0, n = prices.size();
        int least_so_far = prices[0];

        for (int i = 1; i < n; i++)
        {
            if (prices[i] > least_so_far)
            {
                int profit = prices[i] - least_so_far;
                mx = max(mx, profit);
            }
            else
            {
                least_so_far = prices[i];
            }
        }

        return mx;
    }
};
/*
Intution:
We have to maintain variable least_so_far which will be the cheapest stock till now.
Pseudo Code:
 if:
    price[i] > least_so_far => maxProfit = max(maxProfit, price - least_so_far)
 else
    update new least_so_far

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1735493/JavaC%2B%2B-best-ever-EXPLANATION-could-possible
*/
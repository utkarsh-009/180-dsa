/*

Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

/*
DP Solution: [TC: O(n), AS: O(n)]
- keeping track of the minimum stock price seen so far (min_so_far) and
the maximum profit that can be made if selling at the current price (maxProfit).
- At each iteration, it calculates min_so_far and the maximum profit that can be made
i.e. maxProfit = max(maxProfit, prices[i] - min_so_far);
- finally, the maximum profit that can be made is returned.
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        int maxProfit = 0, min_so_far = prices[0];

        for (int i = 0; i < n; i++)
        {
            min_so_far = min(min_so_far, prices[i]);
            maxProfit = max(maxProfit, prices[i] - min_so_far);
        }

        return maxProfit;
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
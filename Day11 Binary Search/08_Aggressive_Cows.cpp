/*
Assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls[n - 1];
        int ans = 0;
        while (low < high)
        {
            int mid = low + (low + high) / 2;
            int cnt = 1; // keeping count as 1 intially as (k-1) checks needed to check whether the minimum distance can be assigned to all  
            int prev = 0;

            // total count of stalls that can be kept at minimum distance mid
            for (int i = 1; i < n && cnt < k; i++)
            {
                // if distance between two stalls is greater or equal to mid
                if (stalls[i] - prev >= mid)
                {
                    prev = stalls[i];
                    cnt++;
                }
            }

            // if no of stalls assigned are more than no of cows
            if (cnt >= k)
            {
                // we store the curr minimum distance, and check if minimum distance between any two of them is the maximum possible
                ans = mid;
                low = mid + 1;
            }
            // else all cows cannot be assigned stalls. Hence, we decrease the minimum distance
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
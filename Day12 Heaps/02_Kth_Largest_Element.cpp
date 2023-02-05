
#include <bits/stdc++.h>
using namespace std;

// Using Priority Queue [Time complexity: O(n), Space Complexity: O(n)]
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        int ans = 0;
        while (!pq.empty() && k--)
        {
            ans = pq.top();
            pq.pop();
        }

        return ans;
    }
};
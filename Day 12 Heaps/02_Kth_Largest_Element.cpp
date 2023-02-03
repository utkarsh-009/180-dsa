

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(k+(n-k)*log(k)) 
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
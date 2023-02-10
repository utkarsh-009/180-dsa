/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/
#include <bits/stdc++.h>
using namespace std;

// HashMap + Priority Queue
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> ans;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto x : mp)
        {
            pq.push({x.second, x.first});
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
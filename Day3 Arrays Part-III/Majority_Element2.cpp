/*
    Input: nums = [3,2,3]
    Output: [3]

    Input: nums = [1,2]
    Output: [1,2]
*/

#include <bits/stdc++.h>
using namespace std;

// Using Unordered Map [TC: O(n), AS: O(n)]
class Solution1
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto x : mp)
        {
            if (x.second > n / 3)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};


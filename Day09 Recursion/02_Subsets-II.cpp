#include <bits/stdc++.h>
using namespace std;

// [TC: O(2^N), AS: O(2^N)]
class Solution
{
public:
    void helper(vector<int> &nums, vector<int> v, int idx, vector<vector<int>> &ans)
    {
        ans.push_back(v);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1]) // Avoid Duplicates
            {
                continue;
            }
            v.push_back(nums[i]);
            helper(nums, v, i + 1, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;

        helper(nums, v, 0, ans);

        return ans;
    }
};
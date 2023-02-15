#include <bits/stdc++.h>
using namespace std;

// [TC: O(2^N), AS: O(2^N)]
class Solution
{
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates, vector<int> v, int target, int curr_sum, int idx)
    {
        if (curr_sum >= target)
        {
            if (curr_sum == target)
            {
                ans.push_back(v);
            }
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            curr_sum += candidates[i];
            v.push_back(candidates[i]);
            helper(candidates, v, target, curr_sum, i);
            curr_sum -= candidates[i];
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        helper(candidates, v, target, 0, 0);

        return ans;
    }
};
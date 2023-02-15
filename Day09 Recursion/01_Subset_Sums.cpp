#include <bits/stdc++.h>
using namespace std;

// [TC: O(2^N), AS: O(2^N)]
class Solution
{
public:
    void helper(vector<int> &arr, int sum, vector<int> &ans, int idx)
    {
        ans.push_back(sum);

        for (int i = idx; i < arr.size(); i++)
        {
            sum += arr[i];
            helper(arr, sum, ans, i + 1);
            sum -= arr[i];
        }
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(arr, 0, ans, 0);

        return ans;
    }
};
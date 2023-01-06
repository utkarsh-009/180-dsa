/*
    Input: nums = [3,2,3]
    Output: 3

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

// Using Unordered Map [TC: O(n), AS: O(n)]
class Solution1
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxFreq = INT_MIN, mxInd = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto x : mp)
        {
            int freq = x.second;
            if (max(freq, maxFreq) == freq)
            {
                mxInd = x.first;
                maxFreq = freq;
            }
        }
        return mxInd;
    }
};

// Using Moore's Vooting Algorithm [TC: O(n), AS: O(1)] (Finding the majority candidate)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 1, candidate_index = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[candidate_index] == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if (cnt == 0)
            {
                candidate_index = i;
                cnt = 1;
            }
        }

        return nums[candidate_index];
    }
};
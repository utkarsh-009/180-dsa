/*
Write a function to find the longest common prefix string amongst an array of strings.

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        int n = strs.size();
        string prefix = "";

        int minLen = INT_MAX;
        for (string s : strs)
        {
            int len = s.length();
            minLen = min(minLen, len);
        }

        for (int i = 0; i < minLen; i++)
        {
            char ch = strs[0][i];
            bool ok = true;
            for (string s : strs)
            {
                if (s[i] != ch)
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
            {
                break;
            }
            prefix.push_back(ch);
        }

        return prefix;
    }
};
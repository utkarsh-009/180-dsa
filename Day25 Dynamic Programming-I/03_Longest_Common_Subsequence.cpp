/*
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

// RECURSIVE APPROACH: [TC: O(2^n), AS: height of recursive of call stack => O(max(n1,n2))]
class Solution1
{
public:
    /*
    RECURSIVE APPROACH: Checking two possibilities at every step.
    1.) if both characters match => 1 + lcs(s1, s2, i1 + 1, i2 + 1);
    2.) if dont match => max(lcs(s1, s2, i1 + 1, i2), lcs(s1, s2, i1, i2 + 1));
    */
    int lcs(string s1, string s2, int i1, int i2)
    {
        // indexes out of bounds => return 0
        if (i1 >= s1.length() || i2 >= s2.length())
        {
            return 0;
        }

        // s1[i1] == s2[i2] => add the characters to current subsequence by increasing lcs length by 1.
        // We also increment both i1 and i2 pointer simultaneously to get next common subsequence
        if (s1[i1] == s2[i2])
        {
            return 1 + lcs(s1, s2, i1 + 1, i2 + 1);
        }

        // else we recursievly call lcs twice incrementing both i1 and i2 pointer individually and max between them will returned.
        else
        {
            return max(lcs(s1, s2, i1 + 1, i2), lcs(s1, s2, i1, i2 + 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return lcs(text1, text2, 0, 0);
    }
};

// DP APPROACH [TC: O(n*n), AS: O(n*n)]: Saving state in table to avoid repitive calculation.
class Solution
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                // s1[i1] == s2[i2] => add the characters to current subsequence by increasing lcs length by 1.
                // We also increment both i1 and i2 pointer simultaneously to get next common subsequence
                if (s1[i] == s2[j])
                {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                }

                // else we consider maximum of lcs obtained by incrementing pointer by 1 i1 and i2 individually.
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // lcs will stored at dp[n1][n2]
        return dp[n1][n2];
    }
};
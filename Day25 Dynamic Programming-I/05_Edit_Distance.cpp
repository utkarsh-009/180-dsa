/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character
*/
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity is 3^m as we have 3 choices at every step
Space Complexity is due to recursion call stack having m size.

Recurrence Relation (NOTE: when characters are matched j decrease)
- Insert Operation: f(i,j-1) as we have inserted character in word1 to be matched with word2
- Delete Operation: f(i-1,j) as we deleted the non-required character from word1
- Replace Operation: f(i-1,j-1) as we replaced the character in word1 to match with word2
*/

// Recursive Approach: [TC: O(3^m), AS: O(m)]
class Solution
{
public:
    int editDist(string w1, string w2, int i1, int i2)
    {
        int n1 = w1.length(), n2 = w2.length();
        // BASE CASE:
        // if i1 is out of bounds => insert rest of the chars
        if (i1 >= w1.length())
        {
            return n2 - i2;
        }

        // if i2 is out of bounds => delete rest of the chars
        if (i2 >= w2.length())
        {
            return n1 - i1;
        }

        // RECURRENCE:
        // if chars same => check for next chars
        if (w1[i1] == w2[i2])
        {
            return editDist(w1, w2, i1 + 1, i2 + 1);
        }

        // if chars not same => delete, insert, replace
        else
        {
            // delete=> editDist(w1,w2,i1+1,i2)
            // insert=> editDist(w1,w2,i1,i2+1)
            // replace=> editDist(w1,w2,i1+1,i2+1)
            return 1 + min(editDist(w1, w2, i1 + 1, i2), min(editDist(w1, w2, i1, i2 + 1), editDist(w1, w2, i1 + 1, i2 + 1)));
        }
    }

    int minDistance(string word1, string word2)
    {
        return editDist(word1, word2, 0, 0);
    }
};

// Iterative Approach [TC: O(N*M), AS: O(N*M)]
class Solution
{
public:
    int minDistance(string w1, string w2)
    {
        int n1 = w1.length(), n2 = w2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // When length of one of the string 0
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = j;
        }

        // Table Filling
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                // if chars same => check for next chars
                if (w1[i] == w2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                // if chars not same => delete, insert, replace
                else
                {
                    dp[i + 1][j + 1] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i][j]));
                }
            }
        }

        return dp[n1][n2];
    }
};
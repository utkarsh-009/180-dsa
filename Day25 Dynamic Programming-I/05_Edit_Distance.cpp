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
class Solution1
{
public:
    int editDist(string s1, string s2, int m, int n)
    {
        // Base Cases:
        if (m == 0) {return n;}

        if (n == 0) {return m;}

        // If last two characters are same
        if (s1[m - 1] == s2[n - 1])
        {
            return editDist(s1, s2, m - 1, n - 1);
        }
        // As last two characters are not same => Insert, Delete, Replace Operations need to be performed
        else
        {
            return 1 + min(editDist(s1, s2, m, n - 1), min(editDist(s1, s2, m - 1, n), editDist(s1, s2, m - 1, n - 1)));
        }
    }

    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        return editDist(word1, word2, m, n);
    }
};

// Iterative Approach [TC: O(N*M), AS: O(N*M)]
class Solution2
{
public:
    int minDistance(string word1, string word2)
    {

        int m = word1.length(), n = word2.length();
        // Create a table to store results of subproblems
        int dp[m + 1][n + 1];

        // If first string is empty, only option is to insert all characters of second string
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }

        // If second string is empty, only option is to remove all characters of first string
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }

        // Fill dp[][] in bottom up manner
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // if characters at current position in 2 strings are equal => No operations performed
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // If the last character is different, consider all possibilities and find the minimum
                else
                {
                    dp[i][j] = 1 + min({dp[i][j - 1],       // Insert
                                        dp[i - 1][j],       // Remove
                                        dp[i - 1][j - 1]}); // Replace
                }
            }
        }

        return dp[m][n]; // returning the no of operations required to make word1 and word2 equal
    }
};


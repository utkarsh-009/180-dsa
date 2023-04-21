/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
Note: From the dictionary B each word can be taken any number of times and in any order.

Input:
    n = 12
    A = "ilikesamsung"
    B = { "i", "like", "sam",
    "sung", "samsung", "mobile",
    "ice","cream", "icecream",
    "man", "go", "mango" }
Output: 1
Explanation: The string can be segmented as "i like samsung" or "i like sam sung".
*/

// Using unordered_set [TC: O(2^n), AS: O(n)]
class Solution1
{
public:
    int solve(string A, vector<string> &B, unordered_set<string> &st, int idx, string curr)
    {
        if (idx >= A.length())
        {
            if (st.find(curr) != st.end())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (st.find(curr) != st.end())
        {
            string newCurr = "";
            newCurr.push_back(A[idx]);
            curr.push_back(A[idx]);
            return solve(A, B, st, idx + 1, newCurr) || solve(A, B, st, idx + 1, curr);
        }

        return solve(A, B, st, idx + 1, curr + A[idx]);
    }

    int wordBreak(string A, vector<string> &B)
    {
        unordered_set<string> st;
        for (int i = 0; i < B.size(); i++)
        {
            st.insert(B[i]);
        }

        return solve(A, B, st, 0, "");
    }
};

// Using DP Tabulation & Unordered Set [TC: O(n*n), AS: O(n)]
class Solution2
{
public:
    int wordBreak(string A, vector<string> &B)
    {

        unordered_set<string> st;
        for (string s : B)
        {
            st.insert(s);
        }

        int n = A.length(), sz = B.size();
        int dp[n + 1] = {0};
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                string s = A.substr(j, i - j + 1);
                if (dp[j] && st.find(s) != st.end())
                {
                    dp[i + 1] = 1;
                }
            }
        }

        return dp[n];
    }
};
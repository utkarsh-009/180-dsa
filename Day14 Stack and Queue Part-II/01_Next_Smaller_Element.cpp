/*

Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that
the element has an index smaller than i.


*/

#include <bits/stdc++.h>
using namespace std;

// Simillar Approach to Next Greater Element [TC: O(n), AS: O(n)]
class Solution
{
public:
    vector<int> prevSmaller(vector<int> &A)
    {
        int n = A.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            // removing all elements greater or equal to current elements
            while (!st.empty() && st.top() >= A[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(A[i]);
        }
        return ans;
    }
};
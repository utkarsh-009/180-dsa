/*

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(n*m), AS: O(n)]
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> v0;

        v0.push_back(1);
        ans.push_back(v0);

        for (int i = 1; i < numRows; i++)
        {
            vector<int> v(i + 1);
            for (int j = 0; j < v.size(); j++)
            {
                int sum = 0;
                if (j == 0 || j == v.size() - 1)
                {
                    v[j] = 1;
                }
                else
                {
                    v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};
/*

*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force:
class Solution1
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back(arr1[i]);
        }

        for (int j = 0; j < m; j++)
        {
            v.push_back(arr2[j]);
        }

        sort(v.begin(), v.end());

        return v[k - 1];
    }
};


// Efficient
/*
    Input:
    n = 4, arr1[] = [1 3 5 7]
    m = 5, arr2[] = [0 2 6 8 9]
    Output:
    arr1[] = [0 1 2 3]
    arr2[] = [5 6 7 8 9]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int nextGap(int gap)
    {
        if (gap == 0 || gap == 1)
        {
            gap = 0;
        }

        else
        {
            gap = gap / 2 + gap % 2;
        }

        return gap;
    }

    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int gap = m + n;

        for (int i = nextGap(gap); i > 0; i = nextGap(i))
        {
            int j = 0;

            // For first array only
            while (j + i < n)
            {
                if (arr1[j] > arr1[j + i])
                {
                    swap(arr1[j], arr1[j + i]);
                }
                j++;
            }

            // For two array
            while (j < n && j + i >= n)
            {
                if (arr1[j] > arr2[j + i - n])
                {
                    swap(arr1[j], arr2[j + i - n]);
                }
                j++;
            }

            // For second array only
            while (j + i < n + m && j >= n)
            {
                if (arr2[j - n] > arr2[j + i - n])
                {
                    swap(arr2[j - n], arr2[j + i - n]);
                }
                j++;
            }
        }
    }
};

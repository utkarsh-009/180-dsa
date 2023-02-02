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
class Solution2
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
        {
            return kthElement(arr2, arr1, m, n, k);
        }

        /*
        arr1[] = {7,12,14,15}
        arr2[] = {1,2,3,4,9,11}

        Here n = 4 and m=6 and k=7. Since k>m, so we can't take 0 elements as the lowest no. of elements picked from array1 .
        It should be (k-m) i.e. 7-6=1 and the high is obvious min(k,n) i.e min(7,4) i.e 4 (4 elements can be taken at max from array 1)
        */
        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high)
        {
            int cut1 = (high + low) / 2;
            int cut2 = k - cut1;

            int l1 = ((cut1 == 0) ? INT_MIN : arr1[cut1 - 1]);
            int l2 = ((cut2 == 0) ? INT_MIN : arr2[cut2 - 1]);
            int r1 = ((cut1 == n) ? INT_MAX : arr1[cut1]);
            int r2 = ((cut2 == m) ? INT_MAX : arr2[cut2]);

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return -1;
    }
};
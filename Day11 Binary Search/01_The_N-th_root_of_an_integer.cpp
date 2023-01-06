/*
Nth Root of a Number using Binary Search

Problem Statement: Given two numbers N and M, find the Nth root of M.
The nth root of a number M is defined as a number X when raised to the power N equals M.

    Input: N=3 M=27
    Output: 3
    Explanation: The cube root of 27 is 3.

NOTE: As the non-perfect nth root are non-terminating numbers. Hence, instead (low <= high), our stopping
condition will be ((high - low) > precision) => performing binary search till the defined precision.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double multiply(double mid, int n)
    {
        double res = 1.0;
        for (int i = 0; i < n; i++)
        {
            res *= mid;
        }
        return res;
    }

    void getNthRootOfM(int n, int m)
    {
        double low = 1, high = m;
        double precision = 1e-6; // for finding precision till 5th decimal place

        while ((high - low) > precision)
        {
            double mid = (low + high) / 2.0;
            double mult = multiply(mid, n);

            if (mult < m)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        cout << n << "th root of " << m << " is " << low << endl;
    }
};

int main()
{
    int n = 3, m = 10;
    Solution obj;
    obj.getNthRootOfM(n, m);
}
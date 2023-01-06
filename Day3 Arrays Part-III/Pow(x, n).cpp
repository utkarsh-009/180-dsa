/*
Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 8.00000
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Code for both +ve/-ve number [TC: O(logn), AS: O(logn)]
class Solution1
{
public:
    double myPow(double x, int n)
    {
        if (n == 0) // Base case
        {
            return 1;
        }
        double temp = myPow(x, abs(n) / 2);
        temp = temp * temp;

        if (abs(n) % 2 == 0)
        {
            return ((n > 0) ? temp : 1 / temp);
        }
        else
        {
            return ((n > 0) ? temp * x : 1 / (temp * x));
        }
    }
};

// Iterative Code for both +ve/-ve number [TC: O(logn), AS: O(1)]
class Solution2
{
public:
    double myPow(double x, int n)
    {
        double res = 1; // To store ans
        long long num = abs(n);
        while (num > 0)
        {
            if (num % 2 != 0)
            {
                res *= x;
                num = num - 1;
            }
            else
            {
                x = x * x;
                num = num / 2;
            }
        }

        return ((n > 0) ? res : 1 / res);
    }
};

/*
Intution:
if num is even => pow(x,num/2) * pow(x,num/2)
if num is odd => pow(x,num-1)*x

Note:
if power is positive => res
if power is negative => 1/res
*/
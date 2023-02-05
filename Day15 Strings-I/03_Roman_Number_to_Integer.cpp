#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(n), AS: O(1)]
class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n;)
        {
            if (i < n - 1 && roman[s[i + 1]] > roman[s[i]])
            {
                ans += (roman[s[i + 1]] - roman[s[i]]);
                i += 2;
            }
            else
            {
                ans += roman[s[i]];
                i++;
            }
        }

        return ans;
    }
};
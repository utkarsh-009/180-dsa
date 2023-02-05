#include <bits/stdc++.h>
using namespace std;

// Storing words in vector [TC: O(n), AS: O(n)]
class Solution1
{
public:
    string reverseWords(string s)
    {

        int n = s.length();
        vector<string> v;

        int i = 0, j = 0;
        string str = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                str += s[i];
            }
            else if (str != "")
            {
                v.push_back(str);
                str = "";
            }
        }

        if (s[n - 1] != ' ')
        {
            v.push_back(str);
        }

        string ans = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += (v[i] + " ");
        }

        ans.pop_back();
        return ans;
    }
};

// Reversing words individually and then reversing the sentence completely [TC: O(n), AS: O(n)]
class Solution2
{
public:
    void reverse(string &s, int low, int high)
    {
        while (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }

    string reverseWords(string s)
    {
        int n = s.length();
        int start = 0;
        for (int end = 0; end < n; end++)
        {
            if (s[end] == ' ')
            {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }

        reverse(s, start, n - 1);
        reverse(s, 0, n - 1);

        // removing whitespaces
        string ans = "";
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                if (temp != "")
                {
                    ans += (temp + " ");
                    temp = "";
                }
            }
        }

        if (temp != "")
        {
            ans += (temp + " ");
        }
        ans.pop_back();
        return ans;
    }
};
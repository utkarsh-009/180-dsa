/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
*/

// [TC: O(n), AS: O(n)]
class Solution
{
public:
    bool isMatching(char a, char b)
    {
        if (a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']')
        {
            return true;
        }

        return false;
    }

    bool isValid(string s)
    {

        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else // closing paratheses
            {
                // If we push closing parantheses in empty stack
                if (st.empty() == true)
                {
                    return false;
                }
                // As open bracket cannot be closed by the same type of brackets
                else if (isMatching(st.top(), c) == false)
                {
                    return false;
                }
                // Open bracket can be closed by same type of brackets
                else
                {
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};
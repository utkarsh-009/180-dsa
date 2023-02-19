/*
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/

#include <bits/stdc++.h>
using namespace std;

// M1: O(n) push and rest all operations O(1)
class MyQueue1
{
public:
    stack<int> st1, st2;

    // O(n)
    void push(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    // O(1)
    int pop()
    {
        int temp = st1.top();
        st1.pop();

        return temp;
    }

    // O(1)
    int peek()
    {
        return st1.top();
    }

    // O(1)
    bool empty()
    {
        return (st1.size() == 0);
    }
};

// M2[Amortised O(1)]: top and pop operation compromised to O(n) for push operations to be in O(1)
/*
- pop and peek operations are performed on output stack after emptying the input stack
- elements are push inside the input stack
*/
class MyQueue2
{
public:
    stack<int> input, output;

    // O(1)
    void push(int x)
    {
        input.push(x);
    }

    // O(n)
    int pop()
    {
        int temp = peek();
        output.pop();

        return temp;
    }

    // O(n)
    int peek()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    // O(1)
    bool empty()
    {
        return (input.empty() && output.empty());
    }
};

/*
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue
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
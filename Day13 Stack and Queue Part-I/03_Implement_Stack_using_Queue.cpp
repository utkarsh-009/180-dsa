/*
Implement a last-in-first-out (LIFO) stack using only queue data structure.
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/

#include <bits/stdc++.h>
using namespace std;

// M1: Use two queues for push operation

// M2: Using single queue, by pushing all elements except the pushed element again to the queue
class MyStack
{
public:
    queue<int> q;

    // O(n)
    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // O(1)
    int pop()
    {
        int temp = q.front();
        q.pop();

        return temp;
    }

    // O(1)
    int top()
    {
        return q.front();
    }

    // O(1)
    bool empty()
    {
        return (q.size() == 0);
    }
};
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <bits/stdc++.h>
using namespace std;

// Using Map and Stack: All Operations O(1)
class MinStack1
{
public:
    stack<int> st;
    map<int, int> mp;

    void push(int val)
    {
        mp[val]++;
        st.push(val);
    }

    void pop()
    {
        mp[st.top()]--;
        if (mp[st.top()] == 0)
        {
            mp.erase(st.top());
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mp.begin()->first;
    }
};

// Using two stacks [TC: O(1), AS: O(1)]
class MinStack2
{
public:
    stack<int> st, min_st;

    void push(int val)
    {
        st.push(val);
        // min_stack store current minimum element
        if (min_st.empty() || min_st.top() >= val) // equality used for duplicates
        {
            min_st.push(val);
        }
    }

    void pop()
    {
        // if current minimum element is equal to element that is to be popped
        if (min_st.top() == st.top())
        {
            min_st.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
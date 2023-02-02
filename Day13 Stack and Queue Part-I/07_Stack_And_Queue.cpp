/*
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
*/

#include <bits/stdc++.h>
using namespace std;

// M1: We using priority queue and push all the elements into it i.e. emptying stack into priority queue.
// And then we empty priority queue to push all the elements into stack

// M2: Recursive
void sortStack(stack<int> &stk, int x)
{
    if (stk.empty())
    {
        stk.push(x);
        return;
    }

    if (x >= stk.top())
    {
        stk.push(x);
    }
    else
    {
        int top = stk.top();
        stk.pop();
        sortStack(stk, x);
        stk.push(top);
    }
}

void helper(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }

    int top = stk.top();
    stk.pop();
    helper(stk);
    sortStack(stk, top);
}

int main()
{
    stack<int> stk;
    stk.push(5);
    stk.push(-2);
    stk.push(9);
    stk.push(-7);
    stk.push(3);

    helper(stk);
}
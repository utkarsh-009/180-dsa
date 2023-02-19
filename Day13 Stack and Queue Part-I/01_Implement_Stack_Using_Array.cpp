/*

*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size; // current size of queue
    int cap;  // total capacity of queue
    int *arr;
    int top;

    // constructor
    Stack(int c)
    {
        size = 0;
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    // functions
    void push(int);
    int pop();
    int getTop();
    int getSize();
    bool isFull();
    bool isEmpty();
};

// O(1)
void Stack::push(int x)
{
    if (top >= cap - 1)
    {
        cout << "Stack is Full" << endl;
        return;
    }

    top++;
    arr[top] = x;
    size++;
}

// O(1)
int Stack::pop()
{
    if (size == 0)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    int temp = arr[top];
    top--;
    size--;

    return temp;
}

// O(1)
int Stack::getTop()
{
    if (size == 0)
    {
        return -1;
    }
    return arr[top];
}

// O(1)
int Stack::getSize()
{
    return size;
}

// O(1)
bool Stack::isEmpty()
{
    return (size == 0);
}

// O(1)
bool Stack::isFull()
{
    return (top >= cap - 1);
}

int main()
{
    Stack *st = new Stack(5);
    cout << "Stack is Empty: " << st->isEmpty() << endl;
    cout << "Top of Stack: " << st->getTop() << endl;
    st->push(5);
    cout << "Top of Stack: " << st->getTop() << endl;
    st->push(53);
    st->push(14);
    st->push(6);
    st->pop();
    cout << "Top of Stack: " << st->getTop() << endl;

    st->push(69);
    cout << "Stack is Full: " << st->isFull() << endl;
}
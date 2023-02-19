/*

*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int size; // current size of queue
    int cap;  // total capacity of queue
    int *arr;
    int front, rear;

    // constructor
    Queue(int c)
    {
        size = 0;
        cap = c;
        arr = new int[cap];
        front = 0;
        rear = -1;
    }

    // functions
    void push(int);
    void pop();
    int getFront();
    int getRear();
    int getSize();
    bool isFull();
    bool isEmpty();
};

// O(1)
void Queue::push(int x)
{
    if (rear >= cap - 1)
    {
        cout << "Queue is Full" << endl;
        return;
    }

    rear++;
    arr[rear] = x;
    size++;
}

// O(1)
void Queue::pop()
{
    if (size == 0)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    front++;
    size--;
}

// O(1)
int Queue::getFront()
{
    if (size == 0)
    {
        return -1;
    }

    return arr[front];
}

// O(1)
int Queue::getRear()
{
    if (size == 0)
    {
        return -1;
    }

    return arr[rear];
}

// O(1)
int Queue::getSize()
{
    return size;
}

// O(1)
bool Queue::isEmpty()
{
    return (size == 0);
}

// O(1)
bool Queue::isFull()
{
    return (rear >= cap - 1);
}

int main()
{
    Queue *q = new Queue(5);
    cout << "Queue is Empty: " << q->isEmpty() << endl;
    q->push(5);
    cout << "Front of Queue: " << q->getFront() << endl;
    q->push(53);
    q->push(14);
    q->push(6);
    q->pop();
    cout << "Front of Queue: " << q->getFront() << endl;
    cout << "Rear of Queue: " << q->getRear() << endl;

    q->push(69);
    cout << "Queue is Full: " << q->isFull() << endl;
}

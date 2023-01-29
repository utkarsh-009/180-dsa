/*
ref link: https://takeuforward.org/data-structure/implement-lru-cache/

Problem Statement: Design a data structure that follows the constraints of Least Recently Used (LRU) cache.
*/
#include <bits/stdc++.h>
using namespace std;

// Using DLL and HashMaps [TC: The functions get and put must each run in O(1) average time complexity, AS: O(max_cap)]
class LRUCache
{
public:
    struct Node
    {
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int max_cap;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        max_cap = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void delNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            int res = resNode->val;
            delNode(resNode);
            addNode(resNode);
            mp[key] = head->next;

            return res;
        }

        return -1;
    }

    void put(int key, int value)
    {
        Node *newNode = new Node(key, value);
        if (mp.find(newNode->key) != mp.end())
        {
            Node *existingNode = mp[key];
            mp.erase(key);
            delNode(existingNode);
        }

        if (mp.size() == max_cap)
        {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        addNode(newNode);
        mp[key] = newNode;
    }
};

/*
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

    Input: head = []
    Output: []
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative
class Solution2
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *curr = head, *prevTOcurr = NULL;
        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prevTOcurr;
            prevTOcurr = curr;

            curr = temp;
        }

        return prevTOcurr;
    }
};
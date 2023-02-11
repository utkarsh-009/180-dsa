/*

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

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

// [TC: O(max(m,n)), AS: O(max(m,n))]
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);

        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }

        int a = ((l1 != NULL) ? l1->val : 0), b = ((l2 != NULL) ? l2->val : 0);
        int sum = a + b, nodeVal = sum % 10, carry = sum / 10;
        head->val = nodeVal;
        ListNode *curr = head;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != NULL && l2 != NULL)
        {
            int a = ((l1 != NULL) ? l1->val : 0), b = ((l2 != NULL) ? l2->val : 0);
            sum = a + b + carry, nodeVal = sum % 10, carry = sum / 10;

            ListNode *temp = new ListNode(nodeVal);
            curr->next = temp;

            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int a = l1->val, b = 0;
            sum = a + b + carry, nodeVal = sum % 10, carry = sum / 10;

            ListNode *temp = new ListNode(nodeVal);
            curr->next = temp;

            curr = curr->next;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int a = 0, b = l2->val;
            sum = a + b + carry, nodeVal = sum % 10, carry = sum / 10;

            ListNode *temp = new ListNode(nodeVal);
            curr->next = temp;

            curr = curr->next;
            l2 = l2->next;
        }

        if (carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            curr->next = temp;
        }

        return head;
    }
};
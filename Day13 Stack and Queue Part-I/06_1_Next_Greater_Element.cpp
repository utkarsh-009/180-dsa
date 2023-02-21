/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
*/

#include <bits/stdc++.h>
using namespace std;

// Using Maps and Nested For Loops [TC: O(n^2), AS: O(n)]
class Solution1
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = -1;
            for (int j = i + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums2[i])
                {
                    mp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};

// Using Map and Stacks [TC: O(n), AS: O(n)]
class Solution2
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> st;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            // we remove all smaller elements from stack (Also keeping note that stack is not empty)
            while (!st.empty() && st.top() < nums2[i])
            {
                st.pop();
            }

            // if stack is empty => No element is stack was greater than current element
            ((st.empty()) ? mp[nums2[i]] = -1 : mp[nums2[i]] = st.top());

            // We push the current element to help us find the next greater element for later iterations
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
return the next greater number for every element in nums.

Input: nums = [1,2,1]
Output: [2,-1,2]

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

// Using Circular Array Modulo Property and Stack [TC: O(n), AS: O(n)]
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            // remove all smaller than or equal to elements in stack
            while (!st.empty() && st.top() <= nums[i % n]) // i%n => Makes index in range of [0,n-1]
            {
                st.pop();
            }

            // filling the next greater elements in the ans vector
            if (i < n)
            {
                if (st.empty())
                {
                    ans[i] = -1;
                }
                else
                {
                    ans[i] = st.top();
                }
            }

            // Pushing the current element to help us find the next greater element for later iterations
            st.push(nums[i % n]);
        }

        return ans;
    }
};
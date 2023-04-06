/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

// RECURSIVE APPROACH [TC: O(2^n), AS: O(2^n)]: Considering two possibilites at every step
class Solution1
{
public:
    int maxProd = INT_MIN;
    void solve(vector<int> &nums, int idx, int curr_prod)
    {
        if (idx >= nums.size())
        {
            maxProd = max(maxProd, curr_prod);
            return;
        }

        // considering the element into current prod i.e. same subarray
        solve(nums, idx + 1, curr_prod * nums[idx]);

        // not considering the element into current prod i.e. new subarray
        maxProd = max(maxProd, curr_prod);
        solve(nums, idx + 1, nums[idx]);
    }

    int maxProduct(vector<int> &nums)
    {
        solve(nums, 1, nums[0]);
        return maxProd;
    }
};

// DP Approach [TC: O(idx*curr_prod), AS: O(idx*curr_prod)]: Storing the solved subproblem in map
class Solution1
{
public:
    int maxProd = INT_MIN;
    void solve(vector<int> &nums, int idx, int curr_prod, map<pair<int, int>, int> &mp)
    {
        if (idx >= nums.size())
        {
            maxProd = max(maxProd, curr_prod);
            mp[{idx, curr_prod}] = maxProd;
            return;
        }

        // Checking if the subproblem is already calculated
        if (mp.find({idx, curr_prod}) != mp.end())
        {
            return;
        }

        // considering the element into current prod i.e. same subarray
        solve(nums, idx + 1, curr_prod * nums[idx], mp);

        // not considering the element into current prod i.e. new subarray
        maxProd = max(maxProd, curr_prod);
        mp[{idx, curr_prod}] = maxProd;
        solve(nums, idx + 1, nums[idx], mp);
    }

    int maxProduct(vector<int> &nums)
    {
        map<pair<int, int>, int> mp;
        solve(nums, 1, nums[0], mp);
        return maxProd;
    }
};

// BEST APPROACH [TC: O(n), AS: O(1)]: Keeping track of both min_prod, max_prod
class Solution3
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int min_prod = 1, max_prod = 1;
        int ans = nums[0];
        for (int i = 0; i < n; i++)
        {
            // Swap is done as when we multiply the min_prod by -ve nums it becomes max_prod and vice versa
            if (nums[i] < 0)
            {
                swap(min_prod, max_prod);
            }

            min_prod = min(min_prod * nums[i], nums[i]);
            max_prod = max(max_prod * nums[i], nums[i]);

            // updating max_prod after every iteration
            ans = max(ans, max_prod);
        }

        return ans;
    }
};
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

/*
DP [TC: O(n), AS: O(n)]
- we return the maximum sum encountered throughout the array, which will be stored in the variable maxSum.
- dp[i] indicates maximum subarray encountered till ith index
- This helps to keep track of the maximum sum encountered so far (maxSum) and update it whenever
we encounter a new maximum sum subarray ending at any index.
*/
class Solution1
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        int maxSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > maxSum)
            {
                maxSum = dp[i];
            }
        }

        return maxSum;
    }
};

/*
Kadane's Algorithm: [TC: O(n), AS: O(1)]
- maintaining two variables: currSum [Current sum] and maxSum [Max Subarray Sum till now]
- initialised as: currSum = 0 and maxSum = nums[0]
- Now we iterate through the vector to find maxSum of subarray:
    1.) currSum += nums[i]
    2.) maxSum = max(currSum, maxSum);
    3.) if(currSum < 0) {currSum = 0;}
- returning the maximum subarray sum [maxSum] encountered till now
*/

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0;
        int maxSum = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0)
            {
                currSum = 0;
            }
        }

        return maxSum;
    }
};
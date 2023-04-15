/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of
the elements in both subsets is equal or false otherwise.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive [TC: O(2^n), AS: O(n*n)]
class Solution {
public:

    bool solve(vector<int>& nums, int i, int total, int currSum)
    {
        if(i >= nums.size()){
            return false;
        }

        if(total - currSum == currSum) {return true;}
        
        // exclude or include element in currSum
        return solve(nums,i+1,total,currSum) || solve(nums,i+1,total,currSum+nums[i]);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++) {total += nums[i];}

        return solve(nums,0,total,0);
    }
};

// DP [TC: O(n*n), AS: O(n*n)]
class Solution {
public:

    bool solve(vector<int>& nums, int i, int total, int currSum, vector<vector<int>>& dp)
    {
        if(i >= nums.size()){
            return false;
        }

        // already computed subproblem
        if(dp[i][currSum] != -1) {return dp[i][currSum];}
        if(total - currSum == currSum) {return dp[i][currSum] = true;}
        
        // exclude or include element in currSum
        return dp[i][currSum] = solve(nums,i+1,total,currSum,dp) || solve(nums,i+1,total,currSum+nums[i],dp);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++) {total += nums[i];}
        vector<vector<int>> dp(n+1, vector<int>(total+1, -1));

        return solve(nums,0,total,0,dp);
    }
};
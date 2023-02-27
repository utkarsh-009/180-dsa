/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/

#include <bits/stdc++.h>
using namespace std;

// Using Stack Concept of Next Smaller Element [TC: O(N), AS: O(N)]
class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // Maintaining next smaller element for both left and right sides
        int leftSmall[n], rightSmall[n];
        stack<int> st;

        // next smaller for element in left side
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){st.pop();}
            
            if(st.empty()) {leftSmall[i] = 0;}
            else {leftSmall[i] = st.top()+1;} // we want the last element just greater or equal to current height

            st.push(i);
        }
        
        // making stack empty to reuse
        while(!st.empty()){st.pop();}

        // next smaller for element in right side
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){st.pop();}
            
            if(st.empty()) {rightSmall[i] = n-1;}
            else {rightSmall[i] = st.top()-1;} // we want the last element just greater or equal to current height

            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i]*(rightSmall[i]-leftSmall[i]+1)); // current_height*width
        }

        return maxArea;
    }
};
/*
You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

// Using Queue (BFS) [TC: O(N*M), AS: O(N)]
class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        int oranges = 0, visited = 0, mins = 0;
        queue<pair<int,int>> rotten;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] != 0) {oranges++;}
                if(grid[i][j] == 2) {rotten.push({i,j});}
            }
        }
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        while(rotten.empty() == false)
        {
            int qSize = rotten.size();
            visited += qSize;
            
            for(int i = 0; i < qSize; i++)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                    {
                        continue;
                    }
                    
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            
            if(!rotten.empty()) {mins++;}
        }
        
        return ((visited == oranges) ? mins : -1);
    }
};
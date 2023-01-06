/*
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]

    Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

#include <bits/stdc++.h>
using namespace std;

// M1: Transpose Matrix And Reverse The Row [TC: O(n*n), AS: O(1)] (Two nested loops required)
class Solution1
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            int low = 0, high = n - 1;
            while (low < high)
            {
                swap(matrix[i][low], matrix[i][high]);
                low++;
                high--;
            }
        }
    }
};

// M2: [TC: O(n*n), AS: O(1)] (Single nested loop required)

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int a = 0, b = n - 1;

        while (a < b)
        {
            for (int i = 0; i < (b - a); i++)
            {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            a++;
            b--;
        }
    }
};
/*
    Input
    1, 2, 3
    4, 5, 6
    7, 8, 9


    for-loop 1
    swap1               swap2               swap3
    1<->3               3<->9              9<->7

    3, 2, 1            9, 2, 1            7, 2, 1
    4, 5, 6    =>      4, 5, 6    =>      4, 5, 6
    7, 8, 9            7, 8, 3            9, 8, 3



    for-loop 2
    swap1              swap2              swap3
    2<->6              6<->8              8<->4

    7, 6, 1            7, 8, 1            7, 4, 1
    4, 5, 2    =>      4, 5, 2    =>      8, 5, 2
    9, 8, 3            9, 6, 3            9, 6, 3


    output
    7, 4, 1,
    8, 5, 2,
    9, 6, 3,
*/
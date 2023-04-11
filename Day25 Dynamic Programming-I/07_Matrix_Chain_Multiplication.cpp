/*

Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i])

Input: N = 5, arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination:
There are 4 matrices of dimension
40x20, 20x30, 30x10, 10x30. Say the matrices are
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D.
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

*/

/*
    MATRIX CHAIN MULTIPLICATION FORMULA:
    Here, i <= k < j, d(i)-> Totol Cost of operation
        C[i,j] = min{C[i,k]+C[k+1,j]+d(i-1)*d(k)*d(j)}
*/

// RECURSION: Using recurrence relation [TC: O(Exponention), AS: O(1) excluding rec call stack]
class Solution1
{
public:
    int solve(int arr[], int i, int j)
    {
        int mini = INT_MAX;

        if (i >= j)
            return 0;

        // Table Filling
        for (int k = i; k < j; k++)
        {
            // Matrix chain multiplication reccurence formula
            int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

            mini = min(mini, temp);
        }

        return mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        int i = 1, j = N - 1;
        return solve(arr, i, j);
    }
};

// DP Approach: [TC: O(N*N*N), AS: O(N*N)]
class Solution2
{
public:
    // No of operations-> i,j
    int t[501][501];

    int solve(int arr[], int i, int j)
    {
        int mini = INT_MAX;

        if (i >= j)
            return 0;

        // if matrix element is change from -1 to any other element => subproblem already calculated
        if (t[i][j] != -1)
            return t[i][j];

        // Table Filling
        for (int k = i; k < j; k++)
        {
            // Matrix chain multiplication reccurence formula
            int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

            mini = min(mini, temp);
        }

        return t[i][j] = mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(t, -1, sizeof(t));

        int i = 1, j = N - 1;
        return solve(arr, i, j);
    }
};
#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative [TC: O(N), AS: O(N)]
class Solution1
{
public:
    int maxDepth(TreeNode *root)
    {

        int max_depth = 0;
        if (root == NULL)
        {
            return max_depth;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int qSize = q.size();

            max_depth++;
            for (int i = 0; i < qSize; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }

                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }

        return max_depth;
    }
};

// Recursive [TC: O(N), AS: O(H)]
class Solution2   
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        return max(maxLeft, maxRight) + 1;
    }
};



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

// Recursive Solution
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &inorder)
    {
        if (root != NULL)
        {
            helper(root->left, inorder);
            inorder.push_back(root->val);
            helper(root->right, inorder);
        }
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        helper(root, inorder);

        return inorder;
    }
};

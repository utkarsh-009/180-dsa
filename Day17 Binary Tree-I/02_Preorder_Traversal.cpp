

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
    void helper(TreeNode *root, vector<int> &preOrder)
    {
        if (root != NULL)
        {
            preOrder.push_back(root->val);
            helper(root->left, preOrder);
            helper(root->right, preOrder);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> preOrder;
        helper(root, preOrder);

        return preOrder;
    }
};
/*
Given the root of a binary tree, return the maximum width of the given tree. The maximum width of a tree is the
maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level
are also counted into the length calculation.
*/

/*
Intutiton (Index Based Approach):
-:To mark every node with indices. This will help us to calculate the width by using indices of two extreme ends.
- NOTE:
parent idx -> i
left child idx -> 2*i+1
right child idx -> 2*i+2
- low,high will be used store the extreme endpoints of particular level: curr_width = high-low+1

Iterative Approach: [TC: O(n), AS: O(w)]
*/
#define ll unsigned long long
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, ll>> q;
        q.push({root, 0});
        ll width = 1;

        while (!q.empty())
        {
            int qSize = q.size();
            ll low = -1, high = -1;
            for (int i = 0; i < qSize; i++)
            {
                TreeNode *curr = q.front().first;
                ll idx = q.front().second;
                q.pop();

                if (low == -1)
                {
                    low = idx;
                }
                else
                {
                    high = idx;
                }

                if (curr->left != NULL)
                {
                    q.push({curr->left, 2 * idx + 1});
                }
                if (curr->right != NULL)
                {
                    q.push({curr->right, 2 * idx + 2});
                }
            }
            if (high != -1)
            {
                width = max(width, high - low + 1);
            }
        }

        return (int)width;
    }
};
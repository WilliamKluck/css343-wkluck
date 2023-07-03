/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *current = root;
        TreeNode *value = new TreeNode(val);
        if (current == nullptr)
        {
            return value;
        }
        // while the node is not inserted
        while (current != value)
        {
            if (current->val < val)
            {
                // checks if there is a right node, if not insert
                if (current->right == nullptr)
                {
                    current->right = value;
                }
                current = current->right;
            }
            if (current->val > val)
            {
                // checks if there is a left node, if not insert
                if (current->left == nullptr)
                {
                    current->left = value;
                }
                current = current->left;
            }
        }
        return root;
    }
};
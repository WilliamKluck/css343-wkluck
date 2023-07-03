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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        stack<TreeNode *> traverse;

        traverse.push(root);
        while (!traverse.empty())
        {
            TreeNode *curr = traverse.top();
            traverse.pop();
            if (curr == nullptr)
            {
                continue;
            }
            preorder.push_back(curr->val);
            traverse.push(curr->right);
            traverse.push(curr->left);
        }

        return preorder;
    }
};
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        // Result vector to store the postorder traversal
        vector<int> res;

        // If the tree is empty, return an empty result vector
        if (root == nullptr)
        {
            return res;
        }

        // Create a stack to store tree nodes
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        stack.push(curr);
        TreeNode *prev = nullptr;

        // Perform postorder traversal using iterative approach
        while (!stack.empty())
        {
            curr = stack.top();

            // If the current node is a leaf or the previous node is its child,
            // add the current node to the result vector and pop it from the stack
            if (prev == nullptr || prev->left == curr || prev->right == curr)
            {
                if (curr->left != nullptr)
                {
                    stack.push(curr->left);
                }
                else if (curr->right != nullptr)
                {
                    stack.push(curr->right);
                }
                else
                {
                    stack.pop();
                    res.push_back(curr->val);
                }
            }
            // If the previous node is the left child of the current node,
            // push the right child of the current node to the stack if it exists,
            // otherwise, add the current node to the result vector and pop it from the stack
            else if (curr->left == prev)
            {
                if (curr->right != nullptr)
                {
                    stack.push(curr->right);
                }
                else
                {
                    stack.pop();
                    res.push_back(curr->val);
                }
            }
            // If the previous node is the right child of the current node,
            // add the current node to the result vector and pop it from the stack
            else if (curr->right == prev)
            {
                stack.pop();
                res.push_back(curr->val);
            }

            // Update the previous node to the current node
            prev = curr;
        }

        // Return the postorder traversal result
        return res;
    }
};

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
    // finds the minimum value in subtree
    TreeNode *findSuccessor(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // deletes node with value key
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        // tree is empty
        if (root == nullptr)
        {
            return nullptr;
        }

        // Current node
        TreeNode *curr = root;
        // Parent of the current node
        TreeNode *parent = nullptr;

        // searching for node placement
        while (curr != nullptr && curr->val != key)
        {
            parent = curr;
            if (key < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        // node not in tree
        if (curr == nullptr)
        {
            return root;
        }

        // key is leaf node or has one child on right
        if (curr->left == nullptr)
        {
            TreeNode *replacer = curr->right;

            // key is root node
            if (parent == nullptr)
            {
                root = replacer;
            }
            else if (curr == parent->left)
            {
                parent->left = replacer;
            }
            else
            {
                parent->right = replacer;
            }
            delete curr;

            // key is leaf node or has one child on left
        }
        else if (curr->right == nullptr)
        {
            TreeNode *replacer = curr->left;

            // key is root node
            if (parent == nullptr)
            {
                root = replacer;
            }
            else if (curr == parent->left)
            {
                parent->left = replacer;
            }
            else
            {
                parent->right = replacer;
            }
            delete curr;

            // key is node with two children
        }
        else
        {

            // Finds the minimum value node in the right subtree
            TreeNode *successor = findSuccessor(curr->right);

            // Replaces the value of node to be deleted with the value of the successor
            curr->val = successor->val;
            TreeNode *replacer = curr->right;

            // If the successor is the right child of the current node
            if (curr->right == successor)
            {
                curr->right = replacer->right;

                // If the successor is further down in the right subtree
            }
            else
            {
                TreeNode *successorParent = curr;
                while (replacer->left != nullptr)
                {
                    successorParent = replacer;
                    replacer = replacer->left;
                }
                successorParent->left = replacer->right;
            }
            delete replacer;
        }

        // returns updated tree
        return root;
    }
};
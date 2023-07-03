/*How does it know that it has reached the last treenode on
 each level and hence the next pointer should be set to null? */
/*ANSWER: My code uses levelSize to make sure that it reaches
 the last treeNode on the level without going over. Use a check
 to see if its the last iteration to know when to set next to null.*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    // uses level order traversal
    Node *connect(Node *root)
    {
        // when none return none
        if (root == nullptr)
        {
            return root;
        }
        queue<Node *> q;
        Node *prev;
        Node *curr = root;
        q.push(curr);
        // continues until all nodes are seen
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                // sets the last node as the prev
                prev = curr;
                curr = q.front();
                q.pop();

                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }
                // on the first node, do not connect just loop
                // on every other node, connect last node to this node
                if (prev != nullptr)
                {
                    prev->next = curr;
                }
                // on the last node, set curr to nullptr
                // this ensures that each level is seperate
                if (i == levelSize - 1)
                {
                    curr->next = nullptr;
                    curr = nullptr;
                }
            }
        }
        return root;
    }
};
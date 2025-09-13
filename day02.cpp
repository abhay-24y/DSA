/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
//----------------------------------------------------- Striver Sheet Question ------------------//
class Solution
{
private:
    bool checkTree(TreeNode *p, TreeNode *q)
    {
        // Both nodes are null
        if (p == nullptr && q == nullptr)
            return true;

        // One is null, the other isn't
        if (p == nullptr || q == nullptr)
            return false;

        // Values must match, and subtrees must match
        if (p->data == q->data)
        {
            return checkTree(p->left, q->left) && checkTree(p->right, q->right);
        }
        else
        {
            return false;
        }
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return checkTree(p, q);
    }
};
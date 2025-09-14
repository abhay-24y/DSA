// Diameter Of A Binary Tree : LeetCode :- 543

class Solution
{
private:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return (1 + max(height(root->left), height(root->right)));
    }
    void solve(TreeNode *root, int &ans)
    {
        if (!root)
            return;
        int temp = height(root->left) + height(root->right);
        if (temp > ans)
        {
            ans = temp;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
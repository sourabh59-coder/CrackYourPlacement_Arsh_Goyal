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
class Solution {
public:
    void fun(TreeNode* &root)
    {
        if(root==NULL)  return;

        TreeNode* r = root->right;
        TreeNode* l = root->left;

        root->left = r;
        root->right = l;
        fun(root->left);
        fun(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        fun(root);
        return root;
    }
};

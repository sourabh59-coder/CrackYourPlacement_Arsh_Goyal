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
    void fun(TreeNode* root,int l,int r,int &ans)
    {
        if(root==NULL)  return;

        if(root->val>=l && root->val<=r)    ans += root->val;

        fun(root->left,l,r,ans);

        fun(root->right,l,r,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        fun(root,low,high,ans);
        return ans;
    }
};

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
    int fun(TreeNode* root,int &ans)
    {
        if(root==NULL) return -1;

        int lh = fun(root->left,ans);

        int rh = fun(root->right,ans);

        ans  = max(ans,lh+rh+2);
        return max(rh,lh) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        fun(root,ans);
        return ans;
    }
};

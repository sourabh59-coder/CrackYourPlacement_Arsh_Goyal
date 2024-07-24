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
    void fun(TreeNode* root,bool flag,int &ans)
    {
        if(root==NULL)  return;

        if(root->left==NULL && root->right==NULL)
        {
            if(flag)    ans += root->val;
            return;
        }

        fun(root->left,true,ans);
        fun(root->right,false,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        fun(root,false,ans);
        return ans;
    }
};

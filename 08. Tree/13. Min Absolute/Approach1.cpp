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
    void fun(TreeNode* root,int &prev,int &ans)
    {
        if(root==NULL)  return;

        fun(root->left,prev,ans);

        if(prev!=-1)
        {
            ans = min(ans,abs(prev-root->val));
        }
        prev = root->val;

        fun(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int ans = INT_MAX;
        fun(root,prev,ans);
        return ans;
    }
};

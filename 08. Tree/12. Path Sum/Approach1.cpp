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
    void fun(TreeNode* root,int &sum,int k,bool &ans)
    {
        if(root==NULL)  return;

        sum += root->val;
        if(sum==k)
        {
            if(root->left==NULL && root->right==NULL)   
            {
                ans = true;
                return;
            }
        }

        fun(root->left,sum,k,ans);

        fun(root->right,sum,k,ans);

        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int sum = 0;
        fun(root,sum,targetSum,ans);
        return ans;
    }
};

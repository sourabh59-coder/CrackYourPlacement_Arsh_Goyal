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
    void fun(TreeNode* a,TreeNode* b,bool &ans)
    {
        if(a==NULL && b==NULL)  return;
        else if(a!=NULL && b!=NULL)
        {
            if(a->val==b->val)
            {
                fun(a->left,b->right,ans);
                fun(a->right,b->left,ans);
            }
            else    
            {
                ans = false;
                return;
            }
        }
        else    ans = false;
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        fun(root,root,ans);
        return ans;
    }
};

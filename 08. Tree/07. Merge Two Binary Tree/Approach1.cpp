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
    TreeNode* fun(TreeNode* a,TreeNode* b)
    {
        if(a==NULL && b==NULL)  return NULL;

        int val = 0;
        if(a)   val += a->val;
        if(b)   val += b->val;

        TreeNode* ans  = new TreeNode(val);

        TreeNode* l_node = NULL;
        TreeNode* r_node = NULL;

        if(a&&b)
        {
            l_node = fun(a->left,b->left);
            r_node = fun(a->right,b->right);
        }
        else if(a)
        {
            l_node = fun(a->left,NULL);
            r_node = fun(a->right,NULL);
        }
        else if(b)
        {
            l_node = fun(NULL,b->left);
            r_node = fun(NULL,b->right);
        }

        ans->right = r_node;
        ans->left = l_node;

        return ans;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return fun(root1,root2);
    }
};

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
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;

        if(root->val==subRoot->val)
        {
            return (check(root->left,subRoot->left) && check(root->right,subRoot->right));
        }
        else    return false;
    }
    bool fun(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL)  return false;

        if(root->val == subRoot->val) 
        {
            if(check(root, subRoot))    return true;
            else    return fun(root->right,subRoot) || fun(root->left,subRoot);
        }
        return fun(root->right,subRoot) || fun(root->left,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return fun(root,subRoot);
    }
};

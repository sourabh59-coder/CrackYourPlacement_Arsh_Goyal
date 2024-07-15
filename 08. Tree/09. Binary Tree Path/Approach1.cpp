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
    void path(TreeNode* a,string temp,vector<string> &ans)
    {
        if(a==NULL) return;

        temp += to_string(a->val);

        if(a->left==NULL && a->right==NULL) ans.push_back(temp);

        temp += "->";

        path(a->left,temp,ans);
        path(a->right,temp,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        path(root,temp,ans);
        return ans;
    }
};

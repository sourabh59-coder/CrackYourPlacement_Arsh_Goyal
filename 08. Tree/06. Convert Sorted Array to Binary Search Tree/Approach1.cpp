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
    TreeNode* fun(vector<int> &v,int l,int r)
    {
        if(l>r) return NULL;
        int mid = (r+l)/2;
        TreeNode* root = new TreeNode(v[mid]);
        TreeNode* l_node = fun(v,l,mid-1);
        TreeNode* r_node = fun(v,mid+1,r);
        root->left = l_node;
        root->right = r_node;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int l = 0;
        int r = v.size()-1;
        return fun(v,l,r);
    }
};

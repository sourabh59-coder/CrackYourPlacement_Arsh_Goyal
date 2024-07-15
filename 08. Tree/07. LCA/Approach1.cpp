/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void fun(TreeNode* root,unordered_map<TreeNode* , TreeNode*> &parent)
    {
        if(root==NULL)  return;

        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if(parent.count(root)==0)   parent[root] = NULL;
        if(l)   parent[l] = root;
        if(r)   parent[r] = root;

        fun(l,parent);
        fun(r,parent);
    } 
    vector<TreeNode*> fun_v(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent)
    {
        vector<TreeNode* > vec;
        
        while(root!=NULL)
        {
            vec.push_back(root);
            root = parent[root];
        }

        reverse(vec.begin(),vec.end());
        return vec;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode* ,TreeNode* > parent;
        fun(root,parent);
        vector<TreeNode*> p_v = fun_v(p,parent);
        vector<TreeNode*> q_v = fun_v(q,parent);
        TreeNode* ans = NULL;
        for(int i=0;i<min(p_v.size(),q_v.size());i++)
        {
            if(p_v[i]==q_v[i])
            {
                ans = p_v[i];
            }
        }
        return ans;
    }
};

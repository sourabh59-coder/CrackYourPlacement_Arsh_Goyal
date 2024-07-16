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
    void dfs(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(root==NULL)  return;

        mp[root] = parent;

        dfs(root->left,root,mp);

        dfs(root->right,root,mp);
    }
    vector<TreeNode*> path(TreeNode* node,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        vector<TreeNode*> ans;

        while(node!=NULL)
        {
            ans.push_back(node);
            node = mp[node];
        }
        // ans.push_back(node);

        reverse(ans.begin(),ans.end());

        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode* ,TreeNode* > mp;
        dfs(root,NULL,mp);

        vector<TreeNode* > vecp = path(p,mp);

        vector<TreeNode* > vecq = path(q,mp);

        int si = min(vecp.size(),vecq.size());

        TreeNode* ans = NULL;

        for(int i=0;i<si;i++)
        {
            if(vecp[i] == vecq[i])
            {
                ans = vecp[i];
            }
        }

        return ans;
    }
};

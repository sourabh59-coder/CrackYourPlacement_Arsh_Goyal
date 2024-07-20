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
    void build(TreeNode* root, vector<int> adj[])
    {
        if(root==NULL)  return;

        int par = root->val;
        if(root->left!=NULL)
        {
            int val = root->left->val;
            adj[val].push_back(par);
            adj[par].push_back(val);
            build(root->left,adj);
        }

        if(root->right!=NULL)
        {
            int val = root->right->val;
            adj[val].push_back(par);
            adj[par].push_back(val);
            build(root->right,adj);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> adj[502];
        build(root,adj);
        vector<int> ans;

        queue<int> qe;
        qe.push(target->val);
        int cnt = 0;
        vector<int> vis(502,0);
        vis[target->val] = 1;
        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;

            if(cnt==k+1)
            {
                while(!qe.empty())
                {
                    ans.push_back(qe.front());
                    qe.pop();
                }
                return ans;
            }
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                for(auto child: adj[it])
                {
                    if(!vis[child])
                    {
                        vis[child] = 1;
                        qe.push(child);
                    }
                }
            }
        }

        return ans;
    }
};

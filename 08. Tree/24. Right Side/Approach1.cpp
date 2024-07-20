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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode* > qe;
        if(root!=NULL)  qe.push(root);
        while(!qe.empty())
        {
            int si = qe.size();
            int val = 0;
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                val = it->val;

                if(it->left)    qe.push(it->left);
                if(it->right)   qe.push(it->right);
            }
            ans.push_back(val);
        }
        return ans;
    }
};

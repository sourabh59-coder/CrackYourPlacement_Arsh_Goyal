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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==NULL)  return ans;

        queue<TreeNode* > qe;
        bool flag = true;
        qe.push(root);

        while(!qe.empty())
        {
            int si = qe.size();
            vector<int> temp;
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                temp.push_back(it->val);
                
                if(it->left)    qe.push(it->left);
                if(it->right)   qe.push(it->right);
            }
            if(!flag)    reverse(temp.begin(),temp.end());

            ans.push_back(temp);
            flag = !(flag);
        }

        return ans;
    }
};

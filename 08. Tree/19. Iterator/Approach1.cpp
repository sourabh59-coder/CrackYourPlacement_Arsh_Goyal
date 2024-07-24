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
class BSTIterator {
public:
    vector<int> inorder;
    int curr;
    void InOrder(TreeNode* root)
    {
        if(root==NULL)  return;

        InOrder(root->left);

        inorder.push_back(root->val);

        InOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        InOrder(root);
        curr = -1;
    }
    
    int next() {
        int n = inorder.size();
        curr++;
        if(curr<n)
        {
            return inorder[curr];
        }
        return -1;
    }
    
    bool hasNext() {
        int n = inorder.size();
        if(curr+1<n)    return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

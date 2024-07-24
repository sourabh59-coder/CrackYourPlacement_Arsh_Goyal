class Solution {
public:
    void bfs(TreeNode* root, map<int, map<int, multiset<int>>>& mp) {
        if (root == NULL) return;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            
            int x = pos.first, y = pos.second;
            mp[x][y].insert(node->val);
            
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        bfs(root, nodes);
        
        vector<vector<int>> result;
        for (auto& [x, ys] : nodes) {
            vector<int> col;
            for (auto& [y, vals] : ys) {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            result.push_back(col);
        }
        return result;
    }
};

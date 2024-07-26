class Solution {
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& v) {
        std::unordered_map<int, std::vector<int>> adj; 
        std::unordered_map<int, int> indegree;        
        
        for (auto& it : v) {
            int a = it[0];
            int b = it[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }

        int start = -1;
        for (const auto& pair : indegree) {
            if (pair.second == 1) { 
                start = pair.first;
                break;
            }
        }

        std::vector<int> ans;
        std::unordered_map<int, bool> vis; 
        std::queue<int> qe;
        
        qe.push(start);
        vis[start] = true;

        while (!qe.empty()) {
            int it = qe.front();
            qe.pop();

            ans.push_back(it);

            for (int child : adj[it]) {
                if (!vis[child]) {
                    vis[child] = true;
                    qe.push(child);
                }
            }
        }
        return ans;
    }
};

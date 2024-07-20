class Solution {
public:
    // const int N = 1e5+9;
    void dfs(int node,vector<int> adj[],vector<int> &vis)
    {
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        int no_of_edges = v.size();
        if(no_of_edges < n-1)   return -1;

        vector<int> adj[n];
        for(int i=0;i<no_of_edges;i++)
        {
            int u = v[i][0];
            int vv = v[i][1];
            adj[u].push_back(vv);
            adj[vv].push_back(u);
        }

        int cnt = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                vis[i] = 1;
                dfs(i,adj,vis);
            }
        }
        
        return cnt-1;
    }
};

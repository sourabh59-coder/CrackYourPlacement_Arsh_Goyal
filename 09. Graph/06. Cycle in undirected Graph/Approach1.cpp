class Solution {
  public: 
    // Function to detect cycle in an undirected graph.
    void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,bool &ans)
    {
        for(auto child: adj[node])
        {
            if(!vis[child])
            {
                vis[child] = 1;
                dfs(child,node,adj,vis,ans);
            }
            else
            {
                if(child!=parent)   ans = true;
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        bool ans = false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                dfs(i,-1,adj,vis,ans);
            }
        }   
        return ans;
    }
};

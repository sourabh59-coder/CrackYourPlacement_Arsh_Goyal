class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &informTime,int &ans,int sum)
    {
        sum += informTime[node];
        ans = max(ans,sum);
        for(auto child: adj[node])
        {
            dfs(child,adj,informTime,ans,sum);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<manager.size();i++)
        {
            int par = manager[i];
            int child = i;
            
            if(par!=-1)
            {
                adj[par].push_back(child);
            }
        }

        int ans = 0;

        dfs(headID,adj,informTime,ans,0);

        return ans;
    }
};

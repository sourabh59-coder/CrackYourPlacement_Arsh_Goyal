//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        
        int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qe;
        qe.push({0,0});
        vector<int> vis(n,0);
        
        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(vis[node])   continue;
            
            vis[node] = 1;
            ans += wt;
            
            for(auto child: adj[node])
            {
                int child_node = child[0];
                int child_wt = child[1];
                
                if(!vis[child_node])
                {
                    qe.push({child_wt,child_node});
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends

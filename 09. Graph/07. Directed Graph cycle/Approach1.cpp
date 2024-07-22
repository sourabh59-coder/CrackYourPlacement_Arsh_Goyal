//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> qe;
        int cnt = 0;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)  qe.push(i);
        }
        
        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();
            
            cnt++;
            
            for(auto child: adj[it])
            {
                indegree[child]--;
                if(indegree[child]==0)  qe.push(child);
            }
        }
        
        return (cnt!=V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

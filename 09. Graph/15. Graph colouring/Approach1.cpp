//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node,int color,vector<vector<int>> &adj,vector<int> &col)
    {
        for(auto child: adj[node])
        {
            if(col[child]==color)   return false;
        }
        return true;
    }
    bool fun(int ind,int n,int m,vector<vector<int>> &adj,vector<int> &col)
    {
        if(ind==n)  return true;
        
        for(int i=1;i<=m;i++)
        {
            if(isSafe(ind,i,adj,col))
            {
                col[ind] = i;
                if (fun(ind + 1, n, m, adj, col)) {
                    return true;
                }
                col[ind] = -1;
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> col(n,-1);
        return fun(0,n,m,adj,col);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

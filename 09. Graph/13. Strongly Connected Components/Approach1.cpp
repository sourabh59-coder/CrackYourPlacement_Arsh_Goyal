//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>> &adj,stack<int> &st,vector<int>  &vis)
	{
	    vis[node] = 1;
	    
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,st,vis);
	        }
	    }
	    
	    st.push(node);
	}
	void dfsK(int node,vector<vector<int>> &adjT,vector<int> &vi,vector<int> &vec)
	{
	    vec.push_back(node);
	    vi[node] = 1;
	    
	    for(auto it: adjT[node])
	    {
	        if(!vi[it])
	        {
	            dfsK(it,adjT,vi,vec);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,st,vis);
            }
        }
        
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        vector<int> vi(V,0);
        
        vector<vector<int>> ans;
        
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            
            if(!vi[it])
            {
                vector<int> vec;
                dfsK(it,adjT,vi,vec);
                ans.push_back(vec);
            }
        }
        
        return ans.size();
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends

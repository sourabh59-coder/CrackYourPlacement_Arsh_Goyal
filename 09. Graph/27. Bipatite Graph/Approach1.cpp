//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &col,bool &ans)
    {
        for(auto child: adj[node])
        {
            if(col[child]==-1)
            {
                col[child] = 1-col[node];
                dfs(child,adj,col,ans);
            }
            else
            {
                if(col[child]==col[node])   ans = false;
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    bool ans = true;
	    for(int i=0;i<V;i++)
	    {
	        if(col[i]==-1)
	        {
	            col[i] = 0;
	            dfs(i,adj,col,ans);
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends

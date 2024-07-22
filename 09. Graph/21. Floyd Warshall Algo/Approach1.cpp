//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    const int INF = 1e8;
	void shortest_distance(vector<vector<int>>&v){
	    // Code here
	    int n = v.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(v[i][j]==-1) v[i][j] = INF;
	        }
	    }
	    
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(v[i][k]!=INF && v[k][j]!=INF)
	                {
	                    v[i][j] = min(v[i][j] , (v[i][k] + v[k][j]));
	                }
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(v[i][j]==INF) v[i][j] = -1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends

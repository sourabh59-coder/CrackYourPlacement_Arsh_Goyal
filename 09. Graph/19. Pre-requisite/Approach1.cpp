//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& v) {
	    // Code here
	    vector<int> adj[N];
	    int n = v.size();
	    for(int i=0;i<n;i++)
	    {
	        int a = v[i].first;
	        int b = v[i].second;
	        adj[b].push_back(a);
	    }
	    
	    int cnt = 0;
	    vector<int> indegree(N,0);
	    for(int i=0;i<n;i++)
	    {
	        indegree[v[i].first]++;
	    }
	    
	    queue<int> qe;
	    for(int i=0;i<N;i++)    if(indegree[i]==0)  qe.push(i);
	    
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
	    
	    return (cnt==N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends

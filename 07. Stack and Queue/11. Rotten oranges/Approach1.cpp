//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int orangesRotting(vector<vector<int>>& v) {
        // Code here
        queue<pair<int,int>> qe;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]==2)  qe.push({i,j});
            }
        }
        
        int n = v.size();
        int m = v[0].size();
        
        if(qe.empty())  return 0;
        
        int cnt = 0;
        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();
                
                int a = it.first;
                int b = it.second;
                
                for(auto moment: moments)
                {
                    int x = a + moment.first;
                    int y = b + moment.second;
                    
                    if(check(x,y,n,m) && v[x][y]==1)
                    {
                        v[x][y] = 2;
                        qe.push({x,y});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)  return -1;
            }
        }
        
        return cnt-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends

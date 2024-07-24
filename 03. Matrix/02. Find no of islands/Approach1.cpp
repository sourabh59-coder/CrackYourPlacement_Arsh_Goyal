//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<pair<int,int>> moments = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(vector<vector<char>> &v,int i,int j,int n,int m)
    {
        v[i][j] = '0';
        
        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;
            
            if(check(x,y,n,m) && v[x][y]=='1')
            {
                dfs(v,x,y,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {
        // Code here
        int cnt = 0;
        int n = v.size();
        int m = v[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='1')
                {
                    cnt++;
                    dfs(v,i,j,n,m);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<pair<pair<int,int>,char>> moments = {{{1,0},'D'},{{0,1},'R'},{{-1,0},'U'},{{0,-1},'L'}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void solve(vector<vector<int>> &v,int i,int j,string &temp,vector<string> &ans,vector<vector<int>> &vis)
    {
        int n = v.size();
        int m = v[0].size();
        if(i==n-1 && j==m-1)
        {
            ans.push_back(temp);
            return;
        }
        
        if(v[i][j]==1)
        {
            for(auto moment: moments)
            {
                int x = i + moment.first.first;
                int y = j + moment.first.second;
                char dir = moment.second;
                
                if(check(x,y,n,m) && v[x][y]==1 && !vis[x][y])
                {
                    temp.push_back(dir);
                    vis[x][y] = 1;
                    solve(v,x,y,temp,ans,vis);
                    temp.pop_back();
                    vis[x][y] = 0;
                }
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &v) {
        // Your code goes here
        int  n = v.size();
        int  m = v[0].size();
        
        vector<string> ans;
        
        if(v[0][0]==0 || v[n-1][m-1]==0)    return ans;
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        string temp;
        vis[0][0] = 1;
        solve(v,0,0,temp,ans,vis);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

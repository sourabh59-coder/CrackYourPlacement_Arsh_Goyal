//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<pair<int, int>> moments = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool check(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(vector<vector<char>>& v, int i, int j, int n, int m, vector<vector<int>>& vis) {
    vis[i][j] = 1;
    
    for (auto moment : moments) {
        int x = i + moment.first;
        int y = j + moment.second;
        
        if (check(x, y, n, m) && v[x][y] == 'O' && !vis[x][y]) {
            dfs(v, x, y, n, m, vis);
        }
    }
}

void dfs_c(vector<vector<char>>& v, int i, int j, int n, int m, vector<vector<int>>& vis) {
    vis[i][j] = 1;
    v[i][j] = 'X';
    
    for (auto moment : moments) {
        int x = i + moment.first;
        int y = j + moment.second;
        
        if (check(x, y, n, m) && !vis[x][y] && v[x][y] == 'O') {
            dfs_c(v, x, y, n, m, vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>>& v) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (v[i][j] == 'O' && !vis[i][j]) {
                    dfs(v, i, j, n, m, vis);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && v[i][j] == 'O') {
                dfs_c(v, i, j, n, m, vis);
            }
        }
    }
    
    return v;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends

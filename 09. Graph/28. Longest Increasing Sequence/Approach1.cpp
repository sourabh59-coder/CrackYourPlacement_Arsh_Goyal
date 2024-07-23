class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int dfs(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1) return dp[i][j];
        int n = v.size();
        int m = v[0].size();
        int maxPath = 1; 

        for (auto moment : moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if (check(x, y, n, m) && v[x][y] > v[i][j])
            {
                maxPath = max(maxPath, 1 + dfs(v, x, y, dp));
            }
        }

        dp[i][j] = maxPath;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(v, i, j, dp));
            }
        }

        return ans;
    }
};

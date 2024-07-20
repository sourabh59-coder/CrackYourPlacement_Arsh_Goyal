class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(int i,int j,vector<vector<char>> &v,vector<vector<int>> &vis)
    {
        int n = v.size();
        int m = v[0].size();
        vis[i][j] = 1;

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(check(x,y,n,m) && !vis[x][y] && v[i][j]=='1')
            {
                dfs(x,y,v,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<vector<int>>  vis(n, vector<int> (m,0));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && v[i][j]=='1')
                {
                    ans++;
                    dfs(i,j,v,vis);
                }
            }
        }

        return ans;
    }
};

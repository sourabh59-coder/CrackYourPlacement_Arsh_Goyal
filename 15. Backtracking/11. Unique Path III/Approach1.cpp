class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool countCellsToVisit(vector<vector<int>>& v,vector<vector<int>> &vis) {
        // int count = 0;
        for (int i=0;i<v.size();i++) {
            for (int j=0;j<v[0].size();j++) {
                if (v[i][j] != -1)
                {
                    if(!vis[i][j])  return false;
                }
            }
        }
        return true;
    }
    int fun(vector<vector<int>> &v,int i,int j,int i_dest,int j_dest,vector<vector<int>> &vis)
    {
        int n = v.size();
        int m = v[0].size();

        if(i==i_dest && j==j_dest)
        {
            if(countCellsToVisit(v,vis))    return 1;
            else                            return 0;
        }

        int ans = 0;

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(check(x,y,n,m) && v[x][y]!=-1 && !vis[x][y])
            {
                vis[x][y] = 1;
                ans += fun(v,x,y,i_dest,j_dest,vis);
                vis[x][y] = 0;
            }
        }

        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& v) {
        int i_src = -1,j_src = -1;
        int i_dest = -1, j_dest = -1;
        int n = v.size();
        int m = v[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    i_src = i;
                    j_src = j;
                }
                if(v[i][j]==2)
                {
                    i_dest = i;
                    j_dest = j;
                }
            }
        }

        vector<vector<int>> vis(n, vector<int> (m,0));
        vis[i_src][j_src] = 1;
        return fun(v,i_src,j_src,i_dest,j_dest,vis);
    }
};

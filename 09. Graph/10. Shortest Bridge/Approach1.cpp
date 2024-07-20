class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs_c(int i,int j,vector<vector<int>> &v)
    {
        int n = v.size();
        int m = v[0].size();
        if(v[i][j]==1)
        {
            v[i][j] = 2;

            for(auto moment:moments)
            {
                int x = i + moment.first;
                int y = j + moment.second;

                if(check(x,y,n,m) && v[x][y]==1)
                {
                    dfs_c(x,y,v);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& v) {
        int n =  v.size();
        int m =  v[0].size();

        bool found = false;
        
        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < m && !found; j++) {
                if(v[i][j] == 1) {
                    dfs_c(i, j, v);
                    found = true;
                }
            }
        }

        vector<vector<int>> vis(n, vector<int> (m,0));
        queue<pair<int,int>> qe;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==2)
                {
                    qe.push({i,j});
                    vis[i][j] = 1;
                }  
            }
        }
        cout<<qe.size()<<endl;
        int ans = -1;
        while(!qe.empty())
        {
            int si = qe.size();
            ans++;
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                int i_ind = it.first;
                int j_ind = it.second;


                if(v[i_ind][j_ind]==1)  return ans-1;

                for(auto moment:moments)
                {
                    int x = i_ind + moment.first;
                    int y = j_ind + moment.second;

                    if(check(x,y,n,m) && !vis[x][y])
                    {
                        vis[x][y] = 1;
                        qe.push({x,y});
                    }
                }
            }
        }
        cout<<"check"<<endl;
        return 0;
    }
};

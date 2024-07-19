class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    void fun(vector<vector<char>> &v,int i,int j,int n,int m,string &temp,string &s,vector<vector<int>> &vis,bool &ans)
    {
        if(temp.size()==s.size())
        {
            if(temp==s) ans = true;
            return;
        }

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y])
            {
                temp.push_back(v[x][y]);
                vis[x][y] = 1;
                fun(v,x,y,n,m,temp,s,vis,ans);
                temp.pop_back();
                vis[x][y] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& v, string s) {
        int n = v.size();
        int m = v[0].size();

        bool ans = false;

        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string temp = "";
                temp.push_back(v[i][j]);
                vis[i][j] = 1;
                fun(v,i,j,n,m,temp,s,vis,ans);
                vis[i][j] = 0;
            }
        }

        return ans;
    }
};

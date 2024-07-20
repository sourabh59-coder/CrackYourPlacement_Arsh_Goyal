class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 &&i<n && j<m);
    }
    void dfs(int i,int j,int color,int curr_color,vector<vector<int>> &v)
    {
        int  n = v.size();
        int  m = v[0].size();
        if(v[i][j]==curr_color)
        {
            v[i][j] = color;

            for(auto moment: moments)
            {
                int x = i + moment.first;
                int y = j + moment.second;

                if(check(x,y,n,m) && v[x][y]==curr_color)
                {
                    dfs(x,y,color,curr_color,v);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color) {
        int n = v.size();
        int m = v[0].size();
        int curr_color = v[sr][sc];
        if(curr_color==color)   return v;

        dfs(sr,sc,color,curr_color,v);
        return v;
    }
};

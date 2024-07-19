class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    void gameOfLife(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> ans(n, vector<int> (m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int neig = 0;
                for(auto moment: moments)
                {
                    int x = i + moment.first;
                    int y = j + moment.second;

                    if(x>=0 && y>=0 && x<n && y<m && v[x][y])   neig++; 
                }
                if(v[i][j]==1)
                {
                    if(neig<2 || neig>3)  ans[i][j] = 0;
                    else                  ans[i][j] = 1;
                }
                else
                {
                    if(neig==3) ans[i][j] = 1;
                }
            }
        }

        v = ans;
    }
};

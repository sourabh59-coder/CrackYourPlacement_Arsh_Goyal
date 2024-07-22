class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int x,int y,int n)
    {
        return (x>=0 && y>=0 && x<n && y<n);
    }
    int maxDistance(vector<vector<int>>& v) {
        int n  = v.size();
        queue<pair<int,int>> qe;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    qe.push({i,j});
                    v[i][j] = 2;
                }
            }
        }

        if(qe.size()==0 || qe.size()==(n*n))    return -1;

        int cnt = 0;
        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;
            for(int loop=0;loop<si;loop++)
            {
                auto it = qe.front();
                qe.pop();

                int i_ind = it.first;
                int j_ind = it.second;

                for(auto moment:moments)
                {
                    int x = i_ind + moment.first;
                    int y = j_ind + moment.second;

                    if(check(x,y,n) && v[x][y]==0)
                    {
                        v[x][y] = 2;
                        qe.push({x,y});
                    }
                }
            }
        }

        return cnt-1;
    }
};

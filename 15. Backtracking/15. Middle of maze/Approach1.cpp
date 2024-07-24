#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};

bool check(int i,int j,int n,int m)
{
    return (i>=0 && j>=0 && i<n && j<m);
}

void fun(vector<vector<int>> &v,int i,int j,int i_dest,int j_dest,vector<pair<int,int>> &temp,vector<vector<pair<int,int>>> &ans,vector<vector<int>> &vis)
{
    int n = v.size();
    if(i==i_dest && j==j_dest)
    {
        ans.push_back(temp);
        return;
    }
    int val = v[i][j];
    for(auto moment:moments)
    {
        int x = i + (moment.first)*val;
        int y = j + (moment.second)*val;

        if(check(x,y,n,n) && !vis[x][y])
        {
            vis[x][y] = 1;
            temp.push_back({x,y});
            fun(v,x,y,i_dest,j_dest,temp,ans,vis);
            temp.pop_back();
            vis[x][y] = 0;
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int> (n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            cin>>v[i][j];

    int i_s = 0, j_s = 0, i_d = 4, j_d = 4;
    vector<pair<int,int>> temp;
    vector<vector<pair<int,int>>> ans;
    vector<vector<int>> vis(n, vector<int> (n,0));
    vis[i_s][j_s] = 1;
    temp.push_back({i_s,j_s});
    fun(v,i_s,j_s,i_d,j_d,temp,ans,vis);
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y.first<<" "<<y.second<<endl;
        }
        cout<<endl;
    }

}

signed main()
{
    solve();
    return 0;
}

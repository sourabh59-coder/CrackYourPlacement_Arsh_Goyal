class Solution {
public:
    const int mod = 2000000000;
    vector<pair<int,int>> moments = {{0,-1},{-1,0}};
    int fun(int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 && m==0)    return 1;

        if(dp[n][m]!=-1)    return dp[n][m];

        int ans = 0;

        for(auto moment: moments)
        {
            int x = moment.first + n;
            int y = moment.second + m;

            if(x>=0 && y>=0)    ans = (ans + fun(x,y,dp)) % mod;
        }

        return dp[n][m] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return fun(m-1,n-1,dp);
    }
};

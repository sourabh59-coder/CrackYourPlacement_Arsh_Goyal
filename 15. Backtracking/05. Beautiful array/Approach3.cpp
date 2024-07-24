class Solution {
public:
    bool isThere(int vis,int i)
    {
        if(((1<<i) & vis)!=0)
        {
            return 1;
        }
        return 0;
    }
    int fun(int ind,int n,int &vis,vector<vector<int>> &dp)
    {
        if(ind==n+1)    return 1;

        if(dp[ind][vis]!=-1)    return dp[ind][vis];

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            if(!isThere(vis,i))
            {
                if(i%ind==0 || ind%i==0)
                {
                    // vis[i] = 1;
                    vis ^= (1 << i);
                    ans += fun(ind+1,n,vis,dp);
                    vis ^= (1 << i);
                }
            }
        }

        return dp[ind][vis] = ans;
    }
    int countArrangement(int n) {
        // vector<int> vis(n+1,0);
        int vis = 0;
        vector<vector<int>> dp(n+1, vector<int> (65540, -1));
        return fun(1,n,vis,dp);
    }
};

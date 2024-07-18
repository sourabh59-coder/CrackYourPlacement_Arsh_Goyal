class Solution {
public:
    int fun(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 && m==0)    return v[0][0];
        if(n<0 || m<0)  return 1e9;

        if(dp[n][m]!=-1)    return dp[n][m];

        int left(0),right(0);

        left = v[n][m] + fun(v,n-1,m,dp);

        right = v[n][m] + fun(v,n,m-1,dp);

        return dp[n][m] = min(left,right);
    }
    int minPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return fun(v,n-1,m-1,dp);
    }
};

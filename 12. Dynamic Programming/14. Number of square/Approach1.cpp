class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        int ans = 0;
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j])
                {
                    if(i==0 || j==0)    dp[i][j] = 1;
                    else                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }

                ans += dp[i][j];
            }
        }
        return ans;
    }
};

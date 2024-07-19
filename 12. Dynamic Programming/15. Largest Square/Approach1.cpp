class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int ans = 0;
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='1')
                {
                    if(i==0 || j==0)    dp[i][j] = 1;
                    else                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};

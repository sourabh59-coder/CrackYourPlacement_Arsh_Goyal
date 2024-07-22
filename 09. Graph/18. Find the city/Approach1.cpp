class Solution {
public:
    const int INF = 1e8;
    int findTheCity(int n, vector<vector<int>>& v, int th) {
        vector<vector<int>> dp(n, vector<int> (n, INF));

        for(int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        for(int i = 0; i < v.size(); i++) {
            int a = v[i][0];
            int b = v[i][1];
            int wt = v[i][2];

            dp[a][b] = wt;
            dp[b][a] = wt;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dp[i][k] != INF && dp[k][j] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }

        int minCount = n;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dp[i][j] <= th) cnt++;
            }
            if(cnt <= minCount) {
                minCount = cnt;
                ans = i;
            }
        }
        return ans;
    }
};

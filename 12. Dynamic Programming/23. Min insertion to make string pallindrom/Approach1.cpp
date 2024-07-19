class Solution {
public:
    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        int lcs_length = dp[0][0];
        return n - lcs_length;
    }
};

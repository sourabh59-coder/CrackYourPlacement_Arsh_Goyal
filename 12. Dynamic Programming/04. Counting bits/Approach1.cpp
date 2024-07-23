class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            if((i & (i - 1)) == 0) { 
                dp[i] = 1;
            } else {
                int highestPowerOfTwo = 1 << (int)log2(i);
                dp[i] = dp[i - highestPowerOfTwo] + 1;
            }
        }
        return dp;
    }
};

class Solution {
public:
    int fun(int n,vector<int> &dp)
    {
        if(n==0)    return 1;

        if(dp[n]!=-1)   return dp[n];

        int one  = 0, two = 0;
        if(n>=1) one = fun(n-1,dp);
        if(n>=2) two = fun(n-2,dp);

        return dp[n] = (one+two);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};

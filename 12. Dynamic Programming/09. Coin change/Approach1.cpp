class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(k==0)    return 0;
            else        return 1e9;
        }

        if(dp[ind][k]!=-1)  return dp[ind][k];

        int notTake = 0 + fun(v,ind+1,n,k,dp);

        int Take = 1e9;

        if(k>=v[ind])   Take = 1 + fun(v,ind,n,k-v[ind],dp);

        return dp[ind][k]= min(Take, notTake);
    }
    int coinChange(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        int val = fun(v,0,n,k,dp);
        return (val>=1e9) ? -1:val;
    }
};

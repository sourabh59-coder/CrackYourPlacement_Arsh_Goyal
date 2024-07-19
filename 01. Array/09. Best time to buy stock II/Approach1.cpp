class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,vector<vector<int>> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        if(buy)
        {
            int notTake = 0 + fun(v,ind+1,n,buy,dp);
            int Take = -v[ind] + fun(v,ind+1,n,0,dp);

            return dp[ind][buy] = max(Take,notTake);
        }
        else
        {
            int notTake = 0 + fun(v,ind+1,n,buy,dp);
            int Take = v[ind] + fun(v,ind+1,n,1,dp);

            return dp[ind][buy] = max(Take,notTake);
        }
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return fun(v,0,n,1,dp);
    }
};

class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,int buy,vector<vector<vector<int>>> &dp)
    {
        if(k==0)    return 0;
        if(ind==n)  return 0;

        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];

        int notTake = 1e9,Take = 1e9;
        if(buy)
        {
            notTake = 0 + fun(v,ind+1,n,k,buy,dp);
            Take = -v[ind] + fun(v,ind+1,n,k,0,dp);
        }
        else
        {
            notTake = 0 + fun(v,ind+1,n,k,buy,dp);
            Take = v[ind] + fun(v,ind+1,n,k-1,1,dp);
        }

        return dp[ind][k][buy] = max(notTake,Take);
    }
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (2,-1)));
        return fun(v,0,n,k,1,dp);
    }
};

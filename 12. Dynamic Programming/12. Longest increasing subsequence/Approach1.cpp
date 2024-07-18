class Solution {
public:
    int fun(vector<int> &v,int ind,int prev,int n,vector<vector<int>> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int notTake = 0 + fun(v,ind+1,prev,n,dp);

        int Take = 0;

        if(prev==-1 || v[prev]<v[ind]) Take = 1 + fun(v,ind+1,ind,n,dp);

        return dp[ind][prev+1] = max(Take,notTake);
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+2,-1));
        return fun(v,0,-1,n,dp);
    }
};

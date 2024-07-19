class Solution {
public:
    int fun(vector<int> &v,int ind,int n,vector<int> &dp)
    {
        if(ind>=n)  return 0;

        if(dp[ind]!=-1) return dp[ind];

        int notTake = 0 + fun(v,ind+1,n,dp);

        int Take = v[ind] + fun(v,ind+2,n,dp);

        return dp[ind] = max(Take,notTake);
    }
    int deleteAndEarn(vector<int>& v) {
        int n = v.size();
        int size = 20001;
        vector<int> vec(size+1,0);
        for(int i=0;i<v.size();i++)
        {
            vec[v[i]] += v[i];
        }
        n = vec.size();
        vector<int> dp(n+1,-1);
        return fun(vec,0,n,dp);
    }
};

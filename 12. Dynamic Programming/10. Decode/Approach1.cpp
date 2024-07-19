class Solution {
public:
    int fun(string &s,int ind,int n,vector<int> &dp)
    {
        if(ind==n)  return 1;

        if(dp[ind]!=-1) return dp[ind];

        int one = 0;
        int two = 0;

        int val = s[ind]-'0';
        if(val!=0)  one = fun(s,ind+1,n,dp);

        if(ind<=n-2)
        {
            int v1 = s[ind]-'0';
            int v2 = s[ind+1]-'0';
            
            int val = (v1*10) + v2;
            if(v1!=0 && val>=10 && val<=26)  two = fun(s,ind+2,n,dp);
        }
        // cout<<one<<" "<<two<<endl;
        return dp[ind] = (one + two);
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return fun(s,0,n,dp);
    }
};

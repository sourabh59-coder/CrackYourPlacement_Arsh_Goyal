class Solution {
public:
    vector<int> moments = {-1,0,+1};
    int isPresent(vector<int> &v,int k)
    {
        int l = 0, r = v.size()-1;
        while(l<=r)
        {
            int mid = (r+l)/2;
            if(v[mid]==k)   return mid;
            else if(v[mid]<k)   l = mid+1;
            else                r = mid-1;
        }
        return -1;
    }
    int fun(vector<int> &v,int ind,int prev,int n,vector<vector<int>> &dp)
    {
        if(ind>=n)   return 0;
        if(ind==n-1)   return 1;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int ans = 0;

        if(prev==-1)
        {
            int val = isPresent(v,v[ind]+1);
            if(val!=-1)
            {
                ans |= fun(v,val,1,n,dp);
            }
        }
        else
        {
            for(auto moment: moments)
            {
                int check = prev + moment;
                if(check>0)
                {
                    int val = isPresent(v,v[ind]+check);
                    if(val!=-1)
                    {
                        ans |= fun(v,val,check,n,dp);
                    }
                }
            }
        }

        return dp[ind][prev+1] = ans;
    }
    bool canCross(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return fun(v,0,-1,n,dp);
    }
};

class Solution {
public:
    int fun(int ind,int n,vector<int> &vis)
    {
        if(ind==n+1)    return 1;

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(i%ind==0 || ind%i==0)
                {
                    vis[i] = 1;
                    ans += fun(ind+1,n,vis);
                    vis[i] = 0;
                }
            }
        }

        return ans;
    }
    int countArrangement(int n) {
        vector<int> vis(n+1,0);
        return fun(1,n,vis);
    }
};

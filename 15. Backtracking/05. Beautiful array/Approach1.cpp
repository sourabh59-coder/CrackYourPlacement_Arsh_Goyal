class Solution {
public:
    void fun(int ind,int n,vector<int> &temp,set<vector<int>> &st,vector<int> &vis)
    {
        if(ind==n+1)
        {
            st.insert(temp);
            return;
        }

        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(i%ind==0 || ind%i==0)
                {
                    vis[i] = 1;
                    temp.push_back(i);
                    fun(ind+1,n,temp,st,vis);
                    temp.pop_back();
                    vis[i] = 0;
                }
            }
        }
    }
    int countArrangement(int n) {
        set<vector<int>> st;
        vector<int> temp;
        vector<int> vis(n+1,0);
        fun(1,n,temp,st,vis);
        return st.size();
    }
};

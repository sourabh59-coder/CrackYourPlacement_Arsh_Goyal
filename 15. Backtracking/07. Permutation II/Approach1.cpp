class Solution {
public:
    void fun(vector<int> &v,int n,vector<int> &temp,set<vector<int>> &st,vector<int> &vis)
    {
        if(temp.size()==n)
        {
            st.insert(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                temp.push_back(v[i]);
                fun(v,n,temp,st,vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n,0);
        set<vector<int>> st;
        fun(v,n,temp,st,vis);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

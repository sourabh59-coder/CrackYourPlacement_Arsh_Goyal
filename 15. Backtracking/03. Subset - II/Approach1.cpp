class Solution {
public:
    void fun(vector<int> &v,int ind,int n,vector<int> &temp,set<vector<int>> &ans)
    {
        if(ind==n)
        {
            ans.insert(temp);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            fun(v,i+1,n,temp,ans);
            temp.push_back(v[ind]);
            fun(v,i+1,n,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        int n = v.size();
        set<vector<int>> ans;
        vector<int> temp;
        fun(v,0,n,temp,ans);
        // return ans;
        vector<vector<int>> final;
        for(auto it:ans)
        {
            final.push_back(it);
        }
        return final;
    }
};

class Solution {
public:
    void fun(vector<int> &v,int ind,int n,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }

            fun(v,ind+1,n,temp,ans);
            temp.push_back(v[ind]);
            fun(v,ind+1,n,temp,ans);
            temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = v.size();
        fun(v,0,n,temp,ans);
        return ans;
    }
};

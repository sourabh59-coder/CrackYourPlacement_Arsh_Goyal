class Solution {
public:
    void fun(int ind,int n,int k,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(k==temp.size())
        {
            ans.push_back(temp);
            return;
        }
        if(ind>n)   return;
        
        temp.push_back(ind);
        fun(ind+1,n,k,temp,ans);
        temp.pop_back();
        fun(ind+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(1,n,k,temp,ans);
        return ans;
    }
};

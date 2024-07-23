class Solution {
public:
    void fun(vector<int> &v,int ind,int n,vector<int> &temp,set<vector<int>> &an,int k)
    {
        if(ind==n)
        {
            if(k==0)
            {
                an.insert(temp);
            }

            return;
        }

        temp.push_back(v[ind]);
        fun(v,ind+1,n,temp,an,k-v[ind]);
        temp.pop_back();
        fun(v,ind+1,n,temp,an,k);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> ans;
        set<vector<int>> an;
        vector<int> temp;
        sort(v.begin(),v.end());
        fun(v,0,n,temp,an,k);
        for(auto it: an)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

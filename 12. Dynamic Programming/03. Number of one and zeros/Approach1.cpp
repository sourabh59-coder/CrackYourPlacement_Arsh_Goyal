class Solution {
public:
    int fun(vector<pair<int,int>> &vec,int ind,int m,int n)
    {
        if(ind==vec.size()) return 0;

        int notTake = 0 + fun(vec,ind+1,m,n);
        
        int Take = 0;
        if(vec[ind].first<=m && vec[ind].second<=n) Take = 1 + fun(vec,ind+1,m-vec[ind].first,n-vec[ind].second);

        return max(Take,notTake);
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        vector<pair<int,int>> vec;
        // int n = str.size();
        for(int i=0;i<str.size();i++)
        {
            int one = 0, zero = 0;
            for(int j=0;j<str[i].size();j++)
            {
                if(str[i][j]=='0')  zero++;
                else                one++;
            }
            vec.push_back({zero,one});
        }
        return fun(vec,0,m,n);
    }
};

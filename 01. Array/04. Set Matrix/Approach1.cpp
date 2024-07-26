class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<int> i_cap(n,0);
        vector<int> j_cap(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                {
                    i_cap[i] = 1;
                    j_cap[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(i_cap[i]==1 || j_cap[j]==1)
                    v[i][j] = 0;
    }
};

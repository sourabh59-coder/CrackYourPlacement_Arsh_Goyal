class Solution {
public:
    bool isSafe(vector<vector<char>> &v,int i,int j,int n,int m,char col)
    {
        int i_dia = 3 * (i / 3);
        int j_dia = 3 * (j / 3);
        for(int k=0;k<9;k++)
        {
            if(v[i][k]==col)    return false;

            if(v[k][j]==col)    return false;

            if(v[i_dia + k/3][j_dia + k%3]==col)    return false;
        }

        return true;
    }
    bool fun(vector<vector<char>> &v,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isSafe(v,i,j,n,m,k))
                        {

                            v[i][j] = k;

                            if(fun(v,n,m))  return true;

                            v[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();

        fun(v,n,m);
    }
};

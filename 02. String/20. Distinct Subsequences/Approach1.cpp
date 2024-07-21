class Solution {
public:
    int fun(string &s, string &t, int i, int j, int n, int m, vector<vector<int>> &memo) {
        if (j == m) return 1; 
        if (i == n) return 0; 

        if (memo[i][j] != -1) return memo[i][j];

        int notTake = fun(s, t, i + 1, j, n, m, memo);

        int take = 0;
        if (s[i] == t[j]) {
            take = fun(s, t, i + 1, j + 1, n, m, memo);
        }

        return memo[i][j] = take + notTake; 
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return fun(s, t, 0, 0, n, m, memo);
    }
};

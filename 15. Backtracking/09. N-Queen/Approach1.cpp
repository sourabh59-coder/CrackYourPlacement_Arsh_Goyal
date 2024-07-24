class Solution {
public:
    void fun(int ind, int n, vector<int> &cols, vector<int> &d1, vector<int> &d2, vector<string> &temp, vector<vector<string>> &ans) {
        if (ind == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (cols[i] == 0 && d1[ind + i] == 0 && d2[ind - i + n - 1] == 0) {
                temp[ind][i] = 'Q';
                cols[i] = 1;
                d1[ind + i] = 1;
                d2[ind - i + n - 1] = 1;
                fun(ind + 1, n, cols, d1, d2, temp, ans);
                temp[ind][i] = '.';
                cols[i] = 0;
                d1[ind + i] = 0;
                d2[ind - i + n - 1] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        vector<int> cols(n, 0);
        vector<int> d1(2 * n - 1, 0);
        vector<int> d2(2 * n - 1, 0);
        fun(0, n, cols, d1, d2, temp, ans);
        return ans;
    }
};

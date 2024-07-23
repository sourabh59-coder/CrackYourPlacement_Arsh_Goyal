class Solution {
public:
    void fun(vector<int> &v, int ind, int n, vector<int> &temp, vector<vector<int>> &ans, int k) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; ++i) {
            if (i > ind && v[i] == v[i-1]) continue; // Skip duplicates

            if (v[i] > k) break; // Prune search if element is greater than remaining target

            temp.push_back(v[i]);
            fun(v, i + 1, n, temp, ans, k - v[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(v.begin(), v.end());
        fun(v, 0, n, temp, ans, k);
        return ans;
    }
};

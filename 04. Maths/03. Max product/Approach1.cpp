class Solution {
public:
    int maximumProduct(vector<int>& v) {
        long long ans = INT_MIN;
        sort(v.begin(), v.end());
        int n = v.size();

        long long val1 = (long long)v[0] * v[1] * v[n-1];
        long long val2 = (long long)v[n-1] * v[n-2] * v[n-3];
        ans = max(val1, val2);

        return (int)ans;
    }
};

class Solution {
public:
    int maximumProduct(vector<int>& v) {
        long long ans = INT_MIN;
        sort(v.begin(),v.end());
        long long prod = 1;
        int n = v.size();
        for(int i=0;i<n-2;i++)
        {
            prod = v[i] * v[i+1] * v[i+2];
            ans = max(ans,prod);
        }
        return (int)ans;
    }
};

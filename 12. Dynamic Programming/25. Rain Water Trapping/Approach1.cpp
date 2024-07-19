class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        vector<int> l = v;
        vector<int> r = v;
        for(int i=1;i<n;i++)    l[i] = max(l[i],l[i-1]);
        for(int i=n-2;i>=0;i--) r[i] = max(r[i],r[i+1]);
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            int val = min(l[i],r[i]);
            ans += abs(val-v[i]);
        }
        return ans;
    }
};

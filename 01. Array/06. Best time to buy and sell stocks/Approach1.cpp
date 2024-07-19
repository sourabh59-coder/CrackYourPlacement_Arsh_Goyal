class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<int> l = v;
        vector<int> r = v;
        for(int i=1;i<n;i++)    l[i] = min(l[i],l[i-1]);
        for(int i=n-2;i>=0;i--) r[i] = max(r[i],r[i+1]);

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,r[i]-l[i]);
        }
        return ans;
    }
};

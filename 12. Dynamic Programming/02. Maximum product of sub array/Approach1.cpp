class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        double pre = 1;
        double suf = 1;
        double ans = v[0];
        for(int i=0;i<n;i++)
        {
            pre *= v[i];
            suf *= v[n-i-1];
            ans = max(ans,max(pre,suf));
            if(pre==0)  pre=1;
            if(suf==0)  suf=1;
        }
        return (int)ans;
    }
};

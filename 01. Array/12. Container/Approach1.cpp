class Solution {
public:
    int maxArea(vector<int>& v) {
        int l = 0 , r = v.size()-1;

        int ans = INT_MIN;

        while(l<r)
        {
            ans = max(ans, (r-l)*(min(v[l],v[r])));
            if(v[l]<v[r])   l++;
            else            r--;
        }
        return ans;
    }
};

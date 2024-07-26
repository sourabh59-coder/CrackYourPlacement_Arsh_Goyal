bool comp(vector<int> &a,vector<int> &b)
{
    return a[1] < b[1];
}
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end(),comp);
        int start = v[0][0];
        int cnt = 0;
        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];

            if(a>=start)
            {
                cnt++;
                start = b;
            }
        }

        return n-cnt;
    }
};

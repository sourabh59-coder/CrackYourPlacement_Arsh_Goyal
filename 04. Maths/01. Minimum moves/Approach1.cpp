class Solution {
public:
    int minMoves2(vector<int>& v) {
        int sum = 0;
        int n = v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n/2;i++)
        {
            sum += v[n-i-1] - v[i];
        }
        return sum;
    }
};

class Solution {
public:
    bool canJump(vector<int>& v) {
        int i = 0;
        int n = v.size();
        int maxv = 0;
        while(i<=maxv && i<n)
        {
            int val = i + v[i];
            maxv = max(maxv,val);
            i++;
        }

        if(i>=n) return true;
        return false;
    }
};

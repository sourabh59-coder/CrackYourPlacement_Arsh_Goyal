class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            int val = abs(v[i]);
            if(v[val-1]<0)  ans.push_back(val);
            v[val-1] *= (-1);
        }
        return ans;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0]++;
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            sum += v[i];
                if(mp.count(sum-k)!=0)
                {
                    ans += mp[sum-k];
                }
            mp[sum]++;
        }
        return ans;
    }
};

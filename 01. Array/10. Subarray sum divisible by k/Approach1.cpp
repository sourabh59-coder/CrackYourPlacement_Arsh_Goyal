class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        long long sum = 0;
        int ans = 0;
        mp[0] = 1;  

        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
            int rem = sum % k;

            if (rem < 0) rem += k;

            if (mp.count(rem) != 0) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};

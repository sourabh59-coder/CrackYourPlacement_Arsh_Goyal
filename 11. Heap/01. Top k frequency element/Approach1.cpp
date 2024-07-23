class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>> qe;
        for(auto it: mp)
        {
            qe.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(qe.top().second);
            qe.pop();
        }
        return ans;
    }
};

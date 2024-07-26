class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(auto it: strs)
        {
            string s = it;
            string ch = s;
            sort(ch.begin(),ch.end());
            mp[ch].push_back(s);
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

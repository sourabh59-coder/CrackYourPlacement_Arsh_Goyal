class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        int n = s.length();
        for(auto it: s)
        {
            mp[it]++;
            if(mp[it] > (n+1)/2)    return "";
        }
        priority_queue<pair<int,char>> qe;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            qe.push({it->second,it->first});
        }
        string ans = "";
        while(qe.size()>1)
        {
            auto it1 = qe.top();
            qe.pop();
            
            auto it2 = qe.top();
            qe.pop();

            ans += it1.second;
            ans += it2.second;

            if(it1.first-1 > 0) qe.push({it1.first-1,it1.second});
            if(it2.first-1 > 0) qe.push({it2.first-1,it2.second});
        }

        if(qe.size()==1)
        {
            ans += qe.top().second;
        }
        return ans;
    }
};

class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }

        priority_queue<int> qe;
        for(auto it: mp)
        {
            qe.push(it.second);
        }

        int ans = 0;
        int prev = -1;

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            // if(prev==0) break;
            if(prev==-1)
            {
                prev = it;
            }
            else
            {
                if(it>prev)
                {
                    ans += (it-prev);
                    it = prev;
                }
                if(it==0)   continue;
                if(prev!=it)    prev = it;
                else            
                {
                    ans++;
                    prev = it-1;
                }
            }
        }

        return ans;
    }
};

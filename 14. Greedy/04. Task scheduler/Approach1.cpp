class Solution {
public:
    // int timer = 0;
    int leastInterval(vector<char>& v, int cool_down) {
        int n = v.size();
        map<char,int> mp;
        for(auto it: v)
        {
            mp[it]++;
        }

        queue<pair<int,int>> qe; // {time,cnt}
        priority_queue<pair<int,int>> p_qe; // {cnt,time}

        for(auto it:mp)
        {
            p_qe.push({it.second,-1});
        }

        int timer = 0;

        while(!qe.empty() || !p_qe.empty())
        {
            while(!qe.empty() && timer - qe.front().first >= cool_down)
            {
                p_qe.push({qe.front().second,qe.front().first});
                qe.pop();
            }

            if(p_qe.empty())
            {
                timer++;
            }
            else
            {
                auto it = p_qe.top();
                p_qe.pop();

                int cnt = it.first;
                int ti = it.second;

                timer++;
                cnt--;
                if(cnt>0)
                {
                    qe.push({timer,cnt});
                }
            }
        }

        return timer;
    }
};

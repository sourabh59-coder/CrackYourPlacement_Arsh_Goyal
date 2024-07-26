class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int ans = 0;
        char prev = '1';
        priority_queue<int,vector<int> ,greater<int>> qe;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(prev!=s[i])
            {
                while(qe.size()>1)
                {
                    ans += qe.top();
                    qe.pop();
                }

                while(!qe.empty())  qe.pop();

                prev = s[i];
                qe.push(v[i]);
            }
            else    qe.push(v[i]);
        }

        if(!qe.empty())
        {
            while(qe.size()>1)
                {
                    ans += qe.top();
                    qe.pop();
                }
        }
        return ans;
    }
};

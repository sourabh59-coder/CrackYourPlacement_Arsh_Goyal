class Solution {
public:
    int furthestBuilding(vector<int>& v, int br, int la) {
        int n = v.size();
        // int ind = 0;
        priority_queue<int, vector<int>, greater<int>> qe;
        long long pr_sum = 0;
        for(int i=1;i<n;i++)
        {
            int val = v[i]-v[i-1];
            if(val>0)
            {
                if(la>0)
                {
                    qe.push(val);
                    la--;
                    pr_sum += val;
                }
                else
                {
                    if(!qe.empty() && val>qe.top())
                    {
                        pr_sum += val;
                        qe.push(val);
                        val = qe.top();
                        pr_sum -= val;
                        qe.pop();
                    }

                    if(br>=val) br -= val;
                    else        return i-1;
                }
            }
        }
        return n-1;
    }
};

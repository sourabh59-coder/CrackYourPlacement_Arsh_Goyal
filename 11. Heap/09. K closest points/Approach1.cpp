class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> qe;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++)
        {
            int f = points[i][0], s = points[i][1];
            int val = pow(f,2)+pow(s,2);
            if(qe.size()<k)
            {
                qe.push({val,points[i]});
            }
            else
            {
                qe.push({val,points[i]});
                qe.pop();
            }
        }

        while(!qe.empty())
        {
            ans.push_back(qe.top().second);
            qe.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

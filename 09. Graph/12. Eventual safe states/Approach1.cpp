class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> adj[n];

        vector<int> outdegree(n,0);
        for(int i=0;i<n;i++)
        {
            outdegree[i] = v[i].size();
            for(int j=0;j<outdegree[i];j++)
            {
                adj[v[i][j]].push_back(i);
            }
        }

        queue<int> qe;
        for(int i=0;i<n;i++)    if(outdegree[i]==0) qe.push(i);

        vector<int>  ans;
        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            ans.push_back(it);

            for(auto child: adj[it])
            {
                outdegree[child]--;
                if(outdegree[child]==0) qe.push(child);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

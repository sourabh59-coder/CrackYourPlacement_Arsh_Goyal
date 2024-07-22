class Solution {
public:
    const int INF = 1e9;
    void Dijikstra(int node,int n,vector<pair<int,int>> adj[],int thres,int &minCount,int &city_no)
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
        // vector<int> vis(n,0);
        vector<int> dist(n,INF);

        qe.push({0,node});
        // vis[node] = 1;
        dist[node] = 0;

        while(!qe.empty())
        {
            auto parent = qe.top();
            qe.pop();

            int par_wt = parent.first;
            int par_node = parent.second;

            for(auto child: adj[par_node])
            {
                int child_node = child.first;
                int child_wt = child.second;
                
                if(par_wt + child_wt < dist[child_node])
                {
                    dist[child_node] = par_wt + child_wt;
                    qe.push({dist[child_node],child_node});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(i!=node && dist[i]<=thres)    cnt++;
        }

        if(minCount>=cnt)
        {
            minCount = cnt;
            city_no = node;
        }
    }
    int findTheCity(int n, vector<vector<int>>& v, int thres) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<v.size();i++)
        {
            int a = v[i][0];
            int b = v[i][1];
            int wt = v[i][2];

            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }

        int minCount = n, city_no = -1;

        for(int i=0;i<n;i++)
        {
            Dijikstra(i,n,adj,thres,minCount,city_no);
        }

        return city_no;
    }
};

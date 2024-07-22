#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

class Solution {
public:
    const int INF = 1e8;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // priority_queue will store {cost, {node, stops}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qe;
        
        // adj will store {destination, weight}
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            int a = it[0];
            int b = it[1];
            int wt = it[2];
            adj[a].emplace_back(b, wt);
        }

        vector<int> dist(n, INF);
        dist[src] = 0;
        qe.push({0, {src, 0}});

        while(!qe.empty()) {
            auto it = qe.top();
            qe.pop();

            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;

            if(node == dst) return cost;
            if(stops > k) continue;

            for(auto& child : adj[node]) {
                int child_node = child.first;
                int child_wt = child.second;

                if(cost + child_wt < dist[child_node]) {
                    dist[child_node] = cost + child_wt;
                    qe.push({cost + child_wt, {child_node, stops + 1}});
                }
            }
        }

        return (dist[dst] == INF) ? -1 : dist[dst];
    }
};

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& v) {
        int n = v.size();
        int cnt_stone = 0;
        int maxRow = 0, maxCol = 0;
        for(auto it:v)
        {
            cnt_stone++;
            int a = it[0];
            int b = it[1];

            maxRow = max(maxRow,a);
            maxCol = max(maxCol,b);
        }

        DisjointSet ds(maxRow+maxCol+1);
        set<int> st;

        for(auto it: v)
        {
            int i = it[0];
            int j = it[1] + maxRow+1;

            ds.unionByRank(i,j);
            st.insert(i);
            st.insert(j);
        }

        int cnt = 0;
        for(auto it: st)
        {
            if(ds.findUPar(it)==it) cnt++;
        }

        return cnt_stone-cnt;
    }
};

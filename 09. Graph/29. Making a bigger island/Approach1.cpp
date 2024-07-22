class DisjointSet {
    vector<int> rank, parent, size; 
    public: 
        DisjointSet(int n) {
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            size.resize(n+1); 
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
                size[i] = 1; 
            }
        }
    
        int findUPar(int node) {
            if(node == parent[node])
                return node; 
            return parent[node] = findUPar(parent[node]); 
        }
    
        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return; 
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v; 
            }
            else if(rank[ulp_v] < rank[ulp_u]) {
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
            if(ulp_u == ulp_v) return; 
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u]; 
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }

        int getSize(int node) {
            int ulp = findUPar(node);
            return size[ulp];
        }
}; 

class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    int DSUind(int i,int j,int n)
    {
        return (i*n) + j;
    }
    bool check(int i,int j,int n)
    {
        return (i>=0 && j>=0 && i<n && j<n);
    }
    int largestIsland(vector<vector<int>>& v) {
        int n = v.size();

        DisjointSet ds(n*n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    int i1 = DSUind(i,j,n);

                    for(auto moment: moments)
                    {
                        int x = moment.first + i;
                        int y = moment.second + j;

                        if(check(x,y,n) && v[x][y])
                        {
                            int i2 = DSUind(x,y,n);

                            ds.unionBySize(i1,i2);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j] == 0)
                {
                    set<int> st;
                    for(auto moment:moments)
                    {
                        int x = i + moment.first;
                        int y = j + moment.second;

                        if(check(x,y,n) && v[x][y]==1)
                        {
                            int i2 = DSUind(x,y,n);
                            st.insert(ds.findUPar(i2));
                        }
                    }
                    int cnt = 1;
                    for(auto it: st)
                    {
                        cnt += ds.getSize(it);
                    }

                    ans = max(ans,cnt);
                }
            }
        }

        return (ans==0) ? (n*n):ans;
    }
};

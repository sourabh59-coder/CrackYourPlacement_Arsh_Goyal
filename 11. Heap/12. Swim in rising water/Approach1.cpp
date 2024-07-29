class Solution {
public:
    bool isValid(int i,int j,int n)
    {
        return (i>=0 && j>=0 && i<n && j<n);
    }
    vector<pair<int,int>> moments = {{0,1},{1,0},{0,-1},{-1,0}};
    int swimInWater(vector<vector<int>>& v) {
        // start = 0 , 0
        // end = n-1 , n-1
        int n = v.size();
        vector<vector<int>> check(n, vector<int> (n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qe;
        qe.push({v[0][0],{0,0}});
        check[0][0] = v[0][0];

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            int val = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for(auto moment: moments)
            {
                int child_x = moment.first + x;
                int child_y = moment.second + y;

                if(isValid(child_x,child_y,n))
                {
                    int value = max(val,v[child_x][child_y]);
                    if(check[child_x][child_y] > value)
                    {
                        check[child_x][child_y] = value;
                        qe.push({value,{child_x,child_y}});
                    }
                }
            }
        }

        return check[n-1][n-1];
    }
};

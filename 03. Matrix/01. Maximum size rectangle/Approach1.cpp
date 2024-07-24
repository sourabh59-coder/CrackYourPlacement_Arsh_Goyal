class Solution {
public:
    vector<int> NSL(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first>=v[i]) st.pop();

            if(st.empty())  ans.push_back(-1);
            else            ans.push_back(st.top().second);

            st.push({v[i],i}); 
        }
        return ans;
    }
    vector<int> NSR(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first>=v[i])
            {
                st.pop();
            }
            if(st.empty())  ans.push_back(n);
            else            ans.push_back(st.top().second);

            st.push({v[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int> l = NSL(v,n);
        vector<int> r = NSR(v,n);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int l_ind = l[i];
            int r_ind = r[i];

            int val = (r_ind - l_ind - 1);
            ans = max(ans,val*v[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m,0);
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]=='1')   v[i]++;
        }
        int ans = 0;
        ans = max(ans,largestRectangleArea(v));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')   v[j]++;
                else                    v[j] = 0;
            }
            ans = max(ans,largestRectangleArea(v));
        }
        return ans;
    }
};

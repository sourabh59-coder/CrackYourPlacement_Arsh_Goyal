class Solution {
public:
    vector<int> NSL(vector<int> &v,int n)
    {
        stack<pair<int,int>> st;
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().second >= v[i])      st.pop();

            if(st.empty())  ans.push_back(-1);
            else            ans.push_back(st.top().first);

            st.push({i,v[i]});
        }

        return ans;
    }

    vector<int> NSR(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().second > v[i])        st.pop();

            if(st.empty())  ans.push_back(n);
            else            ans.push_back(st.top().first);

            st.push({i,v[i]});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        vector<int> left = NSL(v,n);
        vector<int> right = NSR(v,n);

        long long mod = (int)(1e9+7);
        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            long long leftVal = i - left[i];
            long long rightVal = right[i] - i;

            long long val = (leftVal * rightVal)%mod;
            val = (val*v[i])%mod;
            ans = (ans + val)%mod;
        }

        return (int)ans;
    }
};

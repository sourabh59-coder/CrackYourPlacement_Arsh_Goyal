class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        stack<pair<int,int>> st;
        vector<int> ans;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first <= v[i])    
                st.pop();

            if(st.empty())  ans.push_back(0);
            else            ans.push_back(st.top().second-i);   

            st.push({v[i],i}); 
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.size()+n-i > k && st.top() > nums[i]) st.pop();

            st.push(nums[i]);
        }
        while(st.size()>k)  st.pop();
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

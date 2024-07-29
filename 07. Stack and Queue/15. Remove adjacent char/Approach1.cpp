class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string ans;
        int n = s.length();
        
        for(auto it: s) {
            if(st.empty() || st.top().first != it) {
                st.push({it, 1});
            } else {
                if(++st.top().second == k) {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            auto [ch, cnt] = st.top();
            st.pop();
            ans.append(cnt, ch);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

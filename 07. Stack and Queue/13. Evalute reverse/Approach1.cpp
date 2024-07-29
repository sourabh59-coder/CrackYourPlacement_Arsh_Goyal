class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto it: tokens)
        {
            string str = it;
            if(str=="+")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                int val = a+b;
                string temp = to_string(val);
                st.push(temp);
            }
            else if(str=="-")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                int val = b-a;
                string temp = to_string(val);
                st.push(temp);
            }
            else if(str=="*")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                int val = a*b;
                string temp = to_string(val);
                st.push(temp);
            }
            else if(str=="/")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                int val = b/a;
                string temp = to_string(val);
                st.push(temp);
            }
            else    st.push(str);
        }

        int ans = stoi(st.top());
        return ans;
    }
};

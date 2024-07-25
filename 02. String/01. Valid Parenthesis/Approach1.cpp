class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch=='(' || ch=='[' || ch=='{')   st.push(ch);
            
            else
            {
                if(ch==')')
                {
                    if(st.empty())  return false;
                    else if(st.top()=='(')  st.pop();
                    else    return false;
                }
                else if(ch==']')
                {
                    if(st.empty())  return false;
                    else if(st.top()=='[')  st.pop();
                    else    return false;
                }
                else
                {
                    if(st.empty())  return false;
                    else if(st.top()=='{')  st.pop();
                    else    return false;
                }
            }
        }
        
        return (st.empty()) ? true:false;
    }
};

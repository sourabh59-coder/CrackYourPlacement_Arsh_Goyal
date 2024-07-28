//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s) {
        int n = s.length();
        stack<int> st;
    
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                st.push(s[i] - '0');
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val;
                if (s[i] == '+') {
                    val = b + a;
                } else if (s[i] == '-') {
                    val = b - a;
                } else if (s[i] == '/') {
                    val = b / a;
                } else if (s[i] == '*') {
                    val = b * a;
                }
                st.push(val);
            }
        }
    
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends

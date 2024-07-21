class Solution {
public:
    void fun(int open,int close,string &temp,vector<string> &ans)
    {
        if(open==0 && close==0)
        {
            ans.push_back(temp);
            return;
        }

        if(open>0)
        {
            temp.push_back('(');
            fun(open-1,close,temp,ans);
            temp.pop_back();
            // fun(open,close,temp,ans);
        }
        if(close>0 && close>open)
        {
            temp.push_back(')');
            fun(open,close-1,temp,ans);
            temp.pop_back();
            // fun(open,close,temp,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        fun(n,n,temp,ans);
        return ans;
    }
};

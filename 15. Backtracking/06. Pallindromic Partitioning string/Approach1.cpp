class Solution {
public:
    bool isPallindrom(string s)
    {
        int n = s.length();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])  return false;
        }
        return true;
    }
    void fun(string &s,int i,int j,int n,string &check,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        if(j==n)    return;

        check.push_back(s[j]);
        if(isPallindrom(check))
        {
            string check_temp = check;
            temp.push_back(check);
            check = "";
            fun(s,j+1,j+1,n,check,temp,ans);
            check = check_temp;
            temp.pop_back();
        }

        fun(s,i,j+1,n,check,temp,ans);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        string check = "";
        int n = s.length();
        fun(s,0,0,n,check,temp,ans);
        return ans;
    }
};

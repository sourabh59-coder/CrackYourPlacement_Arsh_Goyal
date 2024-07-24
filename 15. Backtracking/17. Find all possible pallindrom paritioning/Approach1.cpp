//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

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
    void fun(string &s,int ind,int n,string &check,vector<string> &temp,vector<vector<string>> &ans,int &cnt)
    {
        if(ind==n)
        {
            if(cnt==n)
            {
                ans.push_back(temp);
            }
            
            return;
        }
        
        check.push_back(s[ind]);
        if(isPallindrom(check))
        {
            temp.push_back(check);
            cnt += check.size();
            string check_temp = check;
            check = "";
            fun(s,ind+1,n,check,temp,ans,cnt);
            temp.pop_back();
            cnt -= check_temp.size();
            check = check_temp;
        }
        
        fun(s,ind+1,n,check,temp,ans,cnt);
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        string check = "";
        int n = s.length();
        int cnt = 0;
        fun(s,0,n,check,temp,ans,cnt);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends

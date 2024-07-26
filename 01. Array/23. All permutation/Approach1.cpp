//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void fun(vector<int> &v,int n,vector<int> &temp,set<vector<int>> &st,vector<int> &vis)
    {
        if(temp.size()==n)
        {
            st.insert(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                temp.push_back(v[i]);
                fun(v,n,temp,st,vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &v ,int n) {
        // code here
        set<vector<int>> st;
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        fun(v,n,temp,st,vis);
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends

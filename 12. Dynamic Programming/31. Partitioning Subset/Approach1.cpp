//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int v[],int ind,int n,int sum,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(sum==0)  return 1;
            else        return 0;
        }
        
        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        
        int notTake = fun(v,ind+1,n,sum,dp);
        
        int Take = 0;
        
        if(v[ind]<=sum) Take = fun(v,ind+1,n,sum-v[ind],dp);
        
        return dp[ind][sum] = (Take || notTake);
    }
    int equalPartition(int n, int v[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<n;i++)    sum += v[i];
        
        if(sum%2!=0)    return 0;
        else
        {
            sum /= 2;
            vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
            return fun(v,0,n,sum,dp);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */


class Solution{
  public:
    bool fun(int v[],int ind,int n,int &k,int &temp,int sum,vector<int> &vis)
    {
        if(ind==n)
        {
            if(k==0)    return true;
            else        return false;
        }
        
        bool ans = false;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(temp+v[i]<=sum)
                {
                    vis[i] = 1;
                    temp += v[i];
                    if(temp==sum)
                    {
                        temp = 0;
                        k--;
                    }
                    
                    ans |= fun(v,ind+1,n,k,temp,sum,vis);
                    if(temp==0)
                    {
                        temp = sum;
                        k++;
                    }
                    temp -= v[i];
                    vis[i] = 0;
                }
            }
        }
        
        return ans;
    }
    bool isKPartitionPossible(int v[], int n, int k)
    {
         //Your code here
         int sum = 0;
         for(int i=0;i<n;i++)   sum += v[i];
         
         if(sum%k!=0)   return false;
         
         sum = sum/k;
         int temp = 0;
         vector<int> vis(n,0);
         return fun(v,0,n,k,temp,sum,vis);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends

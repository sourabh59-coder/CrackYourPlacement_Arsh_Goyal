//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    
    public:
    int fun(int n,int x,int y,int z)
    {
        if(n==0)    return 0;
        
        int ans = 0;
        
        if(n>=x)    ans = max(ans,1+fun(n-x,x,y,z));
        if(n>=y)    ans = max(ans,1+fun(n-y,x,y,z));
        if(n>=z)    ans = max(ans,1+fun(n-z,x,y,z));
        
        return ans;
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        return fun(n,x,y,z);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        long long prod = 1;
        int cnt = 0;
        for(auto it:nums)
        {
            if(it!=0)    prod *=it;
            if(it==0)   cnt++;
        }
        vector<long long int> ans;
        for(auto it: nums)
        {
            if(it==0)
            {
                if(cnt>=2)  ans.push_back(0);
                else        ans.push_back(prod);
            }
            else
            {
                long long int val = prod / it;
                if(cnt!=0)  ans.push_back(0);
                else    ans.push_back(val);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends

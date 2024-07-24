//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        vector<int> v;
        unordered_map<int,int> mp;
        v.push_back(0);
        v.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            int val = v.back() + arr[i];
            v.push_back(val);
        }
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(mp.count(v[i])==0)
            {
                mp[v[i]] = i;
            }
            else
            {
                ans = max(ans,i-mp[v[i]]);
            }
        }
        return ans;
        // Your code here
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

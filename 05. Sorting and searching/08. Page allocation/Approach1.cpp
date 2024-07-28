//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool isPossible(int arr[], int n, int m, long long mid) {
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i= 0 ; i < n ; i++){
            if( pageSum +arr[i]<= mid){
               pageSum += arr[i];
            }
            else{
                studentCount++;
                if(studentCount>m || arr[i]>mid){
                    return false;
                }
                pageSum =arr[i];
            }
        }
        return true;
}

long long findPages(int n, int arr[], int m) {
    long long l = 0;
    long long r = 0;
    if(n<m) return -1;
    for(int i = 0; i < n; i++) {
        if(l < arr[i]) l = arr[i];
        r += arr[i];
    }
    long long result = -1;
    while(l <= r) {
        long long mid = l + (r - l) / 2;
        if(isPossible(arr, n, m, mid)) {
            result = mid;
            // l = mid+1;
            r = mid-1;
        } else {
            // r = mid-1;
            l = mid+1;
        }
    }
    return result;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

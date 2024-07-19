//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    long long fun(int i, int j, int n, vector<vector<int>> &check, vector<vector<vector<long long>>> &memo) {
        if (n == 0) return 1;
        if (memo[i][j][n] != -1) return memo[i][j][n];
    
        long long ans = 0;
        
        ans += fun(i,j,n-1,check,memo);
    
        for (auto movement : movements) {
            int x = i + movement.first;
            int y = j + movement.second;
    
            if (x >= 0 && y >= 0 && x < 4 && y < 3 && check[x][y]) {
                ans += fun(x, y, n - 1, check, memo);
            }
        }
    
        return memo[i][j][n] = ans;
    }
    
    long long getCount(int n) {
        vector<vector<int>> check = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {0, 1, 0}};
        vector<vector<vector<long long>>> memo(4, vector<vector<long long>>(3, vector<long long>(n, -1)));
        long long ans = 0;
    
        for (int i = 0; i < check.size(); i++) {
            for (int j = 0; j < check[0].size(); j++) {
                if (check[i][j]) {
                    ans += fun(i, j, n - 1, check, memo);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends

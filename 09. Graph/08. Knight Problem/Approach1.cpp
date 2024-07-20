//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<pair<int, int>> moments = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};

    bool check(int i, int j, int n)
    {
        return (i >= 1 && j >= 1 && i <= n && j <= n);
    }
    
    int dfs(int i, int j, int i_dest, int j_dest, int n, vector<vector<int>>& vis, vector<vector<int>>& dp)
    {
        if (i == i_dest && j == j_dest) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
    
        int ans = 1e8;
        for (auto moment : moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;
            
            if (check(x, y, n) && !vis[x][y])
            {
                vis[x][y] = 1;
                ans = min(ans, 1 + dfs(x, y, i_dest, j_dest, n, vis, dp));
                vis[x][y] = 0;
            }
        }
        
        dp[i][j] = ans;
        return ans;
    }
    
    int minStepToReachTarget(vector<int>& ini, vector<int>& des, int N)
    {
        int i_start = ini[0];
        int j_start = ini[1];
        int i_dest = des[0];
        int j_dest = des[1];
        
        vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        
        vis[i_start][j_start] = 1;
        int result = dfs(i_start, j_start, i_dest, j_dest, N, vis, dp);
        
        return result == 1e8 ? -1 : result;  
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

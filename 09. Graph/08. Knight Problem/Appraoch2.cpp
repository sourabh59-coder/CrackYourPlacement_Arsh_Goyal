//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<pair<int,int>> moments = {{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
    bool check(int i,int j,int n)
    {
        return (i>=1 && j>=1 && i<=n && j<=n) ;
    }
	int minStepToReachTarget(vector<int>&start,vector<int>&dest,int n)
	{
	    // Code here
	    int i = start[0];
	    int j = start[1];
	    int dest_i = dest[0];
	    int dest_j = dest[1];
	    
	    queue<pair<int,int>> qe;
	    qe.push({i,j});
	    vector<vector<int>> vis(n+1, vector<int> (n+1,0));
	    vis[i][j] = 1;
	    
	    
	    int cnt = 0;
	    
	    while(!qe.empty())
	    {
	        int si = qe.size();
	        cnt++;
	        
	        for(int i=0;i<si;i++)
	        {
	            auto it = qe.front();
	            qe.pop();
	            
	            int i_par = it.first;
	            int j_par = it.second;
	            
	            if(i_par==dest_i && j_par==dest_j)
	            {
	                return cnt-1;
	            }
	            
	            for(auto moment: moments)
	            {
	                int x = i_par + moment.first;
	                int y = j_par + moment.second;
	                
	                if(check(x,y,n) && !vis[x][y])
	                {
	                    vis[x][y] = 1;
	                    qe.push({x,y});
	                }
	            }
	        }
	    }
	    
	    return -1;
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

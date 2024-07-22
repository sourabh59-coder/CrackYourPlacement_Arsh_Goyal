//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string v[], int n, int k) {
        //code here
        // size of graph = k
        if(n==1)    return "1";
        vector<int> adj[k];
        // string first = v[0];
        for(int i=0;i<n-1;i++)
        {
            string s1 = v[i];
            string s2 = v[i+1];
            
            for(int j=0;j<min(s1.length(),s2.length());j++)
            {
                if(s1[j]!=s2[j])
                {
                    int a = s1[j]-'a';
                    int b = s2[j]-'a';
                    
                    adj[a].push_back(b);
                    break;
                }
            }
        }
        
        vector<int> indegree(k,0);
        vector<int> vis(k,0);
        
        for(int i=0;i<k;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> qe;
        
        for(int i=0;i<k;i++)    if(indegree[i]==0)  qe.push(i);
        
        // int cnt = 0;
        string ans = "";
        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();
            
            // cnt++;
            char ch = it + 'a';
            ans += ch;
            
            for(auto child: adj[it])
            {
                indegree[child]--;
                if(indegree[child]==0)  qe.push(child);
            }
        }
        
        return (ans.size()==k) ? ans : "0";
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

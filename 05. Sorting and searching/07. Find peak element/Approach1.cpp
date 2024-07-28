#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
int n;
cin>>n;

vector<int> v(n);
for(int i=0;i<n;i++)  cin>>v[i];

int sum = 0;
for(int i=0;i<n/2;i++)  ans += abs(v[i]-v[n-i-1]);

cout<<ans<<endl;
return 0;
}

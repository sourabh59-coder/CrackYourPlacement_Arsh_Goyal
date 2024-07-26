#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    int k;
    cin>>k;

    sort(v.begin(),v.end());

    int ans = 0;
    
    int i =0 ,j = n-1;
    while(i<=j)
    {
        ans += v[i];
        i++;
        j -= k;
    }

    cout<<ans<<endl;
}

signed main()
{
    solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> arr,seg;

void build(int i,int l,int r)
{
    if(l==r)
    {
        seg[i] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    
    seg[i] = min(seg[2*i+1], seg[2*i+2]);
}

void updateValue(int i,int l,int r,int ind,int val)
{
    if(l==r)
    {
        seg[i] = val;
        return;
    }    
    
    int mid = (r+l)/2;
    
    if(ind<=mid)
    {
        updateValue(2*i+1,l,mid,ind,val);
    }
    else
    {
        updateValue(2*i+2,mid+1,r,ind,val);
    }
    
    seg[i] = min(seg[2*i+1],seg[2*i+2]);
}

int rangeAnd(int i,int l,int r,int lq,int rq)
{
    if(lq>r || rq<l)    return INT_MAX;
    if(lq<=l && r<=rq)  return seg[i];
    
    int mid = (r+l)/2;
    return min( rangeAnd(2*i+1,l,mid,lq,rq) , rangeAnd(2*i+2,mid+1,r,lq,rq) );
}

void solve()
{
    int n;
    cin>>n;
    
    arr.resize(n);
    
    for(int i=0;i<n;i++)    cin>>arr[i];
    
    seg.resize(4*n);
    
    build(0,0,n-1);
    
    
    int q;
    cin>>q;
    
    while(q--)
    {
        int type;
        cin>>type;
        
        if(type==1)
        {
            int ind,val;
            cin>>ind>>val;
            
            updateValue(0,0,n-1,ind,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            
            cout<<rangeAnd(0,0,n-1,l,r)<<endl;
        }
    }
}

signed main()
{
    solve();
    return 0;
}

#include <bits/stdc++.h>

bool isPossible(vector<int> &v,int n,int k,int thres)
{
    int prev = v[0];
    int cnt = 0;

    for(int i=1;i<n;i++)
    {
        if(v[i]-prev>=thres)
        {
            cnt++;
            prev = v[i];
        }
    }

    return (cnt>=k);
}

int aggressiveCows(vector<int> &v, int k)
{
    //    Write your code here.
    sort(v.begin(),v.end());
    int n = v.size();
    int prev = v[0];
    int l = 1;
    int r = v[n-1];

    k--;

    int temp = -1;

    while(l<=r)
    {
        int mid = (r-l)/2 + l;

        if(isPossible(v,n,k,mid))
        {
            temp = mid;
            l = mid+1;
        }
        else    r = mid-1;
    }

    // for(int i=l;i<=r;i++)
    // {
    //     if(isPossible(v,n,k,i))
    //     {
    //         temp = i;
    //     }
    // }

    return temp;
}

class Solution {
public:
    bool check(vector<int> &v,int limit,int k)
    {
        int student = 1;
        int sum = 0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            sum += v[i];
            if(sum>limit)
            {
                sum = v[i];
                student++;
            }
            if(student>k)   return 0;
        }
        return 1;
    }
    int fun(vector<int> &v,int l,int r,int k)
    {
        int temp = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(check(v,mid,k))
            {
                temp = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return temp;
    }
    int splitArray(vector<int>& v, int k) {
        int n = v.size();
        int l = INT_MIN;
        int r = 0;
        for(int i=0;i<n;i++)
        {
            l = max(l,v[i]);
            r += v[i];
        }

        return fun(v,l,r,k);
    }
};

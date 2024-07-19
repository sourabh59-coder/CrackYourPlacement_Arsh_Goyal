class Solution {
public:
    int BinarySearch(vector<int> &v,int l,int r,int k)
    {
        while(l<=r)
        {
            int mid = (r+l)/2;
            if(v[mid]==k)   return mid;
            else if(v[mid]<k)   l = mid+1;
            else                r = mid-1;
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int  n = v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int  l = j+1, r = n-1;
                int val = v[i] + v[j];
                val = (-1) * val;
                int search = BinarySearch(v,l,r,val);
                if(search!=-1)  
                {
                    st.insert({v[i],v[j],v[search]});
                }
            }
        }

        for(auto it: st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

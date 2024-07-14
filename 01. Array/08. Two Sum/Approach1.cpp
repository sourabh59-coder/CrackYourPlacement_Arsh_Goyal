class Solution {
public:
    int BinarySearch(vector<pair<int,int>> &v,int l,int r,int k)
    {
        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(v[mid].first == k)   return v[mid].second;
            else if(v[mid].first < k)     l = mid + 1;
            else                    r = mid - 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        int n = nums.size();

        for(int i=0;i<n;i++)    v.push_back({nums[i],i});

        sort(v.begin(),v.end());

        for(int i=0;i<n-1;i++)
        {
            int temp = BinarySearch(v,i+1,n-1,target-v[i].first);

            if(temp!=-1)    return {v[i].second, temp};
        }

        return {};
    }
};

class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n-1;
        int mid = 0;

        while(mid<=r)
        {
            if(v[mid]==0)
            {
                swap(v[mid],v[l]);
                l++;
                mid++;
            }
            else if(v[mid]==1)
            {
                mid++;
            }
            else if(v[mid]==2)
            {
                swap(v[mid],v[r]);
                r--;
            }
        }
    }
};

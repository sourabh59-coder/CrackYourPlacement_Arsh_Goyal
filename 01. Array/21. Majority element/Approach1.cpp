class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int ele = v[0];
        int cnt = 1;
        for(int i=1;i<n;i++)
        {
            if(cnt==0)  
            {
                ele = v[i];
                cnt = 1;
            }
            else
            {
                if(ele==v[i])   cnt++;
                else            cnt--;
            }
        }
        return ele;
    }
};

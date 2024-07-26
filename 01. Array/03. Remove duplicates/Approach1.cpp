class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        int i = 0, j = 1;
        while(j!=n)
        {
            if(v[i]!=v[j])
            {
                v[i+1] = v[j];
                i++;
            }
            j++;
        }
        return (i+1);
    }
};

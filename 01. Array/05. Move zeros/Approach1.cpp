class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        if (n == 1) return;
        int i = 0, j = 0;
        
        while (j < n) {
            if (v[j] != 0) {
                swap(v[i], v[j]);
                i++;
            }
            j++;
        }
    }
};

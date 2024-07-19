class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int sum = 0;
        int ans = 0;

        for (int i = n - k; i < n; i++) {
            sum += v[i];
        }
        
        ans = sum;
        int leftSum = 0;
        int rightSum = sum;
        
        for (int i = 0; i < k; i++) {
            leftSum += v[i];
            rightSum -= v[n - k + i];
            ans = max(ans, leftSum + rightSum);
        }
        
        return ans;
    }
};

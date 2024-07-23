class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> qe;
        for(auto it: nums)
        {
            qe.push(it);
            if(qe.size()>k) qe.pop();
        }
        return qe.top();
    }
};

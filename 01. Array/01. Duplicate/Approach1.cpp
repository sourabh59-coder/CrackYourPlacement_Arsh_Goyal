class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = 0;
        int fast = 0;
        do{
            slow = v[slow];
            fast = v[v[fast]];
        }while(slow!=fast);

        fast = 0;
        while(fast!=slow)
        {
            slow = v[slow];
            fast = v[fast];
        }
        return slow;
    }
};

class NumArray {
public:
    vector<int> seg;
    int n;

    // Function to build the segment tree
    void build(int i, int l, int r, vector<int> &nums) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    // Function to update the segment tree
    void make(int index, int val, int l, int r, int i) {
        if (l == r) {
            seg[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid) {
            make(index, val, l, mid, 2 * i + 1);
        } else {
            make(index, val, mid + 1, r, 2 * i + 2);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    // Function to get the sum range
    int Sum(int i, int l, int r, int lq, int rq) {
        if (lq > r || rq < l) return 0;
        if (lq <= l && r <= rq) return seg[i];
        int mid = (l + r) / 2;
        return Sum(2 * i + 1, l, mid, lq, rq) + Sum(2 * i + 2, mid + 1, r, lq, rq);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        make(index, val, 0, n - 1, 0);
    }
    
    int sumRange(int left, int right) {
        return Sum(0, 0, n - 1, left, right);
    }
};

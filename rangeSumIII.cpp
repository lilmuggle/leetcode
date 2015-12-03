//binary indexed tree
class NumArray {
public:
    vector<int> num, t;
    NumArray(vector<int> &nums) {
        num = nums;
        t = vector<int>(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            upDate(i + 1, nums[i]);
    }

    int lowbit(int n) {
        return n & -n;
    }

    void update(int i, int val) {
        upDate(i + 1, val - num[i]);
        num[i] = val;
    }

    void upDate(int i, int val) {
        while(i <= num.size()) {
            t[i] += val;
            i += lowbit(i);
        }
    }

    int sum(int idx) {
        int s = 0;
        while(idx > 0) {
            s += t[idx];
            idx -= lowbit(idx);
        }
        return s;
    }

    int sumRange(int i, int j) {
        if(i >= num.size())
            return 0;
        if(j >= num.size())
            j = num.size() - 1;
        return i == 0 ? sum(j + 1) : sum(j + 1) - sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

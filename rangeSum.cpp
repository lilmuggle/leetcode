class NumArray {
public:
    vector<int> a;
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            a.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if(i >= a.size())
            return 0;
        if(j >= a.size())
            j = a.size() - 1;
        return i == 0 ? a[j] : a[j] - a[--i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

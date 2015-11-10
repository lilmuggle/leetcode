class Solution {
public:
    int helper(vector<int>& a, int *low, int *high, int x) {
        while(*low <= *high) {
            int mid = *low + (*high - *low) / 2;
            if(a[mid] == x)
                return mid;
            if(a[mid] < x)
                *low = mid + 1;
            else
                *high = mid - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int low = 0, high = nums.size() - 1;
        int index = helper(nums, &low, &high, target);
        int tmp1 = index, tmp2 = index;
        while(tmp1 != -1) {
            res[0] = tmp1;
            tmp1 = helper(nums, &low, &(--tmp1), target);
        }
        while(tmp2 != -1) {
            res[1] = tmp2;
            tmp2 = helper(nums, &(++tmp2), &high, target);
        }
        return res;
    }
};

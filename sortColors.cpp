class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i, head = 0, tail = nums.size() - 1;
        while(i <= tail) {
            if(nums[i] == 0 && i > head)
                swap(nums[i], nums[head++]);
            else if(nums[i] == 2)
                swap(nums[i], nums[tail--]);
            else
                i++;
        }
    }
};

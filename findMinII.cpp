class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, low = 0, high = nums.size() - 1;
        while(low < high) {
            if(nums[low] < nums[high])
                return nums[low];
            mid = low + (high - low) / 2;
            if(nums[low] > nums[mid])
                high = mid;
            else if(nums[high] == nums[mid]) {
                low++;
                high--;
            }
            else
                low = mid + 1;
        }
        return nums[low];
    }
};

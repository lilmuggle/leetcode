int search(int* nums, int numsSize, int target) {
    int low, high, mid;
    low = 0;
    high = numsSize - 1;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] >= nums[low])
            if(nums[mid] < target)
                low = mid + 1;
            else {
                if(nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        else {
            if(nums[mid] > target)
                high = mid - 1;
            else {
                if(nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    return -1;
}

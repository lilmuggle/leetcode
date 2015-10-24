bool search(int* nums, int numsSize, int target) {
    int low, high, mid;
    low = 0;
    high = numsSize - 1;
    while (low < high) {
        if (nums[low] < nums[high])
             break;
        mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if(nums[mid] < nums[high])
            high = mid;
        else {
            int tmp = high;
            while(high > mid) {
                if(nums[high] != nums[mid])
                    break;
                high--;
            }
            if(high > mid) {
                low = mid + 1;
                high = tmp;
            }
        }
    }
    int rot = low;
    low = 0;
    high = numsSize - 1;
    while(low <= high) {
        mid = low + (high - low) / 2;
        int realmid = (mid + rot) % numsSize;
        if(nums[realmid] == target)
            return true;
        if(nums[realmid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

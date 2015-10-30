int findDuplicate(int* nums, int numsSize) {
    int low, high, mid, greater, less;
    low = 1;
    high = numsSize - 1;
    while(low <= high) {
        mid = low + (high - low) / 2;
        greater = less = 0;
        for(int i = 0; i < numsSize; i++) {
            if(nums[i] > mid)
                greater++;
            else if(nums[i] < mid)
                less++;
        }
        if(less > mid - 1)
            high = mid - 1;
        else if(greater > numsSize - 1 - mid)
            low = mid + 1;
        else
            return mid;
    }
}

//Others
int findDuplicate(int* nums, int numsSize)
{
    if (numsSize() > 1)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    return -1;
}

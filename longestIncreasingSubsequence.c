int lengthOfLIS(int* nums, int numsSize) {
    int maxlis = 0, lis[numsSize];
    for(int i = numsSize - 1; i >= 0; i--) {
        lis[i] = 1;
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] < nums[j])
                lis[i] = lis[i]>lis[j]+1?lis[i]:lis[j] + 1;
        }
        maxlis = maxlis > lis[i] ? maxlis : lis[i];
    }
    return maxlis;
}

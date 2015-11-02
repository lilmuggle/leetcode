int rob(int* nums, int numsSize) {
    if(numsSize == 1)
        return nums[0];
    int i, j, a[numsSize];
    a[0] = 0;
    a[1] = nums[0];
    for(i = 2; i < numsSize; i++)
        a[i] = a[i-2]+nums[i-1]>a[i-1]?a[i-2]+nums[i-1]:a[i-1];
    int tmp = a[i - 1];
    a[1] = 0;
    a[2] = nums[1];
    for(j = 3; j <= numsSize; j++)
        a[j] = a[j-2]+nums[j-1]>a[j-1]?a[j-2]+nums[j-1]:a[j-1];
    return tmp>a[j-1]?tmp:a[j-1];
}

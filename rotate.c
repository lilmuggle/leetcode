void rotate(int* nums, int numsSize, int k) {
    int i, j, *tmp;
    k %= numsSize;
    tmp = (int *)malloc(sizeof(int) * k);
    for(i = 0; i < k; i++)
        tmp[i] = nums[numsSize - 1 - i];
    for(j  = numsSize - 1, i = numsSize - k - 1; i >= 0; j--, i--)
        nums[j] = nums[i];
    for(; j >= 0; j--)
        nums[j] = tmp[k - 1 - j];
}

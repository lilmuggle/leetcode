/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i, diff = 0, *a;
    *returnSize = 2;
    a = (int *)malloc(sizeof(int) * 2);
    for(i = 0; i < numsSize; i++)
        diff ^= nums[i];
    diff &= -diff;
    a[0] = a[1] = 0;
    for(i = 0; i < numsSize; i++) {
        if((nums[i] & diff) == 0)
            a[0] ^= nums[i];
        else
            a[1] ^= nums[i];
    }
    return a;
}

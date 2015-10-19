/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i, front = 1, back = 1, *a;
    *returnSize = numsSize;
    a = malloc(sizeof(int) * numsSize);
    for(i = 0; i < numsSize; i++) {
        a[i] = front;
        front *= nums[i];
    }
    for(i = numsSize - 1; i >= 0; i--) {
        a[i] *= back;
        back *= nums[i];
    }
    return a;
}

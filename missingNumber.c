//Original
int missingNumber(int *nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
        sum += nums[i];
    return (numsSize * (numsSize + 1)) / 2 - sum;
}

//Others
int missingNumber(int *nums, int numsSize){
    int result = numsSize;
    for(int i = 0; i < numsSize; i++) {
        result ^= nums[i];
        result ^= i;
        i++;
    }
    return result;
}

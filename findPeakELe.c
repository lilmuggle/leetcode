int findPeakElement(int* nums, int numsSize) {
    if(numsSize < 2)
        return 0;
    for(int i = 0; i < numsSize - 1; i++) {
        if(a[i] > a[i + 1])
            return i;
    }
    return numsSize - 1;
}

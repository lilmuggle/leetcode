int removeDuplicates(int* nums, int numsSize) {
    if(numsSize < 3)
        return numsSize;
    int i, begin = 0;
    for(i = 1; i < numsSize; i++) {
        if(nums[i] != nums[begin])
            nums[++begin] = nums[i];
        else {
            if(begin == 0 || nums[begin] != nums[begin - 1])
                nums[++begin] = nums[i];
        }
    }
    return ++begin;
}

//After improvement
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    for(int j = 0; j < numsSize; j++) {
        if(i < 2 || nums[j] > nums[i - 2])
            nums[i++] = nums[j];
    }
    return i;
}

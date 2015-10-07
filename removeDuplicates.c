int removeDuplicates(int* nums, int numsSize) {
    if(numsSize < 2)
        return numsSize;

    int i, begin;

    i = 1;
    begin = 0;
    while(i < numsSize)
    {
        if(nums[i] != nums[begin])
        {
            nums[++begin] = nums[i];
        }
        else
            i++;
    }
    return begin + 1;
}

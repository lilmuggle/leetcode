void sortColors(int* nums, int numsSize) {
    int i, num0 = 0, num1 = 0;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] == 0)
            num0++;
        else if(nums[i] == 1)
            num1++;
    }
    for(i = 0; i < numsSize; i++) {
        if(i < num0)
            nums[i] = 0;
        else if(i < (num0 + num1))
            nums[i] = 1;
        else
            nums[i] = 2;
    }
}

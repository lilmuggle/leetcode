bool canJump(int* nums, int numsSize) {
    int i = 0, count;
    while(i < numsSize - 1) {
        if(nums[i] == 0) {
            count = 1;
            while(i >= 0 && nums[i] < count) {
                i--;
                count++;
            }
            if(i < 0)
                return false;
            else
                i += count;
        }
        else
            i += nums[i];
    }
    return true;
}

//After improvement
bool canJump(int* nums, int numsSize) {
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if(i > max)
            return false;
        max = (i + nums[i]) > max ? (i + nums[i]) : max;
    }
    return true;
}

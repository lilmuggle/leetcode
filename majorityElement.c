int majorityElement(int *nums, int numsSize)
{
    int i;
    int count = 0;
    int candidate = 0;

    for(i =  0; i < numsSize; i++)
    {
        if(count == 0)
            candidate = nums[i];
        if(candidate == nums[i])
            count++;
        else
            count--;
    }

    return candidate;
}

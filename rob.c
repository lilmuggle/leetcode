int rob(int* nums, int numsSize)
{
    int i, a1, a2, a[numsSize];

    a[0] = 0;
    a[1] = nums[0];
    for(i = 2; i <= numsSize; i++)
    {
        a1 = a[i - 2] + nums[i - 1];
        a2 = a[i - 1];
        if(a1 >= a2)
            a[i] = a1;
        else
            a[i] = a2;
    }
    return a[numsSize];
}

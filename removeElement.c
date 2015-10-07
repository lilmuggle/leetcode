//Original
int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0)
        return 0;

    int i, j;
    i = 0;
    j = numsSize - 1;
    while(i <= j)
    {
        if(nums[i] == val)
        {
            numsSize--;
            while(nums[j] == val && i < j)
            {
                numsSize--;
                j--;
            }
            nums[i] = nums[j];
            j--;
        }
        i++;
    }
    return numsSize;
}

//After improvement
int removeElement(int A[], int n, int elem) {
    int begin=0;
    for(int i=0;i<n;i++)
        if(A[i]!=elem)
            A[begin++]=A[i];
    return begin;
}

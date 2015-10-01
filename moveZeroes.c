#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
    int i, j, temp;

    for(i = 0; i < numsSize; i++)
    {
        temp = nums[i];
        for(j = i; j > 0 && nums[j - 1] == 0; j--)
            nums[j] = nums[j - 1];
        nums[j] = temp;
    }
}

void main()
{
    int i;
    int numSize;
    int a[100];

    printf("pls input the numsize: ");
    scanf("%d", &numSize);
    printf("pls input numbers: ");
    for(i = 0; i < numSize; i++)
        scanf("%d", &a[i]);
    moveZeroes(a, numSize);
    printf("After moving, nums:");
    for(i = 0; i < numSize; i++)
        printf("%d ", a[i]);
}

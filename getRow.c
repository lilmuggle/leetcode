/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Original
int* getRow(int rowIndex, int* returnSize) {
    int i, j, *a, *b;

    *returnSize = rowIndex + 1;
    a = (int *)malloc(sizeof(int) * (*returnSize));
    b = (int *)malloc(sizeof(int) * (rowIndex));
    b[0] = a[0] = 1;
    for(i = 1; i <= rowIndex; i++)
    {
        for(j = 1; j < i; j++)
            a[j] = b[j] + b[j -1];
        if(j == i)
            a[j] = 1;
        for(j = 1; j < rowIndex; j++)
            b[j] = a[j];
    }

    return a;
}

//After improvement
int* getRow(int rowIndex, int* returnSize)
{
    int i, j, *a;

    *returnSize = rowIndex + 1;
    a = (int *)malloc(sizeof(int) * (*returnSize));
    a[0] = 1;
    for(i = 1; i <= rowIndex; i++)
    {
        for(j = i; j > 0; j--)
            a[j] += a[j - 1];
    }
    return a;
}

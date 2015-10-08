/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int i, j, **a;

    *returnSize = numRows;
    *columnSizes = (int *)malloc(sizeof(int) * numRows);
    a = (int **)malloc(sizeof(int *) * numRows);
    for(i = 0; i < numRows; i++)
    {
        (*columnSizes)[i] = i + 1;
        a[i] = (int *)malloc(sizeof(int) * (i + 1));
    }
    for(i = 0; i < numRows; i++)
        a[i][0] = 1;
    for(i = 1; i < numRows; i++)
    {
        for(j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        a[i][j] = 1;
    }
    return a;
}

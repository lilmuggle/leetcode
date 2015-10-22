/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *a, i, j, c = 0, k = 0, prod;
    prod = matrixRowSize*matrixColSize;
    a = malloc(sizeof(int)*prod);
    while(c < prod) {
        for(i = j = k; j < matrixColSize; j++)
            a[c++] = matrix[i][j];
        if(c >= prod)
            break;
        for(i = k + 1, j = matrixColSize - 1; i < matrixRowSize; i++)
            a[c++] = matrix[i][j];
        if(c >= prod)
            break;
        for(i = matrixRowSize - 1, j = matrixColSize - 2;  j >= k; j--)
            a[c++] = matrix[i][j];
        for(i = matrixRowSize - 2, j = k; i > k; i--)
            a[c++] = matrix[i][j];
        k++;
        matrixRowSize--;
        matrixColSize--;
    }
    return a;
}

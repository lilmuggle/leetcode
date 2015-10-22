/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **a, i, j, prod, k = 0, num = 1;
    prod = n * n;
    a = malloc(sizeof(int*) * n);
    for(i =  0; i < n; i++)
        a[i] = malloc(sizeof(int) * n);
    while(num <= prod) {
        for(i = j = k; j < n; j++)
            a[i][j] = num++;
        for(i = k + 1, j = n - 1; i < n; i++)
            a[i][j] = num++;
        for(i = n - 1, j = n - 2;  j >= k; j--)
            a[i][j] = num++;
        for(i = n - 2, j = k; i > k; i--)
            a[i][j] = num++;
        k++;
        n--;
    }
    return a;
}

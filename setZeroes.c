void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j, *r, *c;
    r = malloc(sizeof(int) * matrixRowSize);
    c = malloc(sizeof(int) * matrixColSize);
    for(i = 0; i < matrixRowSize; i++)
        r[i] = 0;
    for(j = 0; j < matrixColSize; j++)
        c[j] = 0;
    for(i = 0; i < matrixRowSize; i++) {
        for(j = 0; j < matrixColSize; j++) {
            if(matrix[i][j] == 0)
                r[i] = c[j] = 1;
        }
    }
    for(i = 0; i < matrixRowSize; i++) {
        if(r[i] == 1) {
            for(j = 0; j < matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for(j = 0; j < matrixColSize; j++) {
        if(c[j] == 1) {
            for(i = 0; i < matrixRowSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

//O(1)space
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int col0 = 1;
    for (int i = 0; i < matrixRowSize; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < matrixColSize; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    for (int i = matrixRowSize - 1; i >= 0; i--) {
        for (int j = matrixColSize - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}

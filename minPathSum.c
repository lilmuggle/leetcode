#define m 2147483647
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i, down, right;
    down = right = m;
    if(gridRowSize == 1 && gridColSize == 1)
        return grid[0][0];
    if(gridRowSize > 1)
        right = minPathSum(grid, gridRowSize - 1, gridColSize);
    if(gridColSize > 1)
        down = minPathSum(grid, gridRowSize, gridColSize - 1);
    return right<down?right+grid[gridRowSize-1][gridColSize-1]:down+grid[gridRowSize-1][gridColSize-1];
}

#define m 2147483647
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i, j, left, up;
    for(i = 0; i < gridRowSize; i++) {
        for(j = 0; j < gridColSize; j++) {
            left = up = m;
            if(j > 0)
                left = grid[i][j - 1];
            if(i > 0)
                up = grid[i - 1][j];
            if(i != 0 || j != 0)
                grid[i][j] += left < up ? left : up;
        }
    }
    return grid[gridRowSize - 1][gridColSize - 1];
}

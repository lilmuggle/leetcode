bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
   int low, high, mid;
   for(int r = 0; r < matrixRowSize; r++) {
        low = 0;
        high = matrixColSize - 1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(matrix[r][mid] == target)
                return true;
            if(matrix[r][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
   }
   return false;
}

//O(m + n)
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int r = 0, c = matrixColSize - 1;
    while(r < matrixRowSize && c >= 0) {
        if(matrix[r][c] < target)
            r++;
        else if(matrix[r][c] > target)
            c--;
        else
            return true;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int low, high, mid, row;
    low = 0;
    high = matrixRowSize - 1;
    while(low < high) {
        mid = low + (high - low) / 2;
        if(target == matrix[mid][0])
            return true;
        if(target > matrix[mid][0]){
            if(target > matrix[mid][matrixColSize - 1])
                low = mid + 1;
            else {
                low = mid;
                break;
            }
        }
        else
            high = mid - 1;
    }
    row = low;
    low = 0;
    high = matrixColSize - 1;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(target == matrix[row][mid])
            return true;
        if(target > matrix[row][mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

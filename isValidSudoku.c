bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int n, row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};

    for(int r = 0; r < 9; r++)
        for(int c = 0; c < 9; c++)
            if(board[r][c] != '.')
            {
                n = board[r][c] - '1';
                if(row[r][n]++)
                    return false;
                if(col[c][n]++)
                    return false;
                if(box[r/3+c/3*3][n]++)
                    return false;
            }
    return true;
}

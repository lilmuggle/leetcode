#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    int **buffer = malloc(sizeof(int*) * 2);
    buffer[0] = malloc(sizeof(int) * boardColSize);
    buffer[1] = malloc(sizeof(int) * boardColSize);
    for(int i = 0; i < boardRowSize; i++) {
        if(i > 1) {
            for(int k = 0; k < boardColSize; k++)
                board[i - 2][k] = buffer[i % 2][k];
        }
        for(int j = 0; j < boardColSize; j++) {
            int sum = 0;
            for(int I=max(i-1,0);I<min(i+2,boardRowSize);I++) {
                for(int J=MAX(j-1,0);J<min(j+2,boardColSize);J++)
                    sum += board[I][J];
            }
            /*
            int sum = board[i][j];
            if(j > 0)
                sum += board[i][j - 1];
            if(j < boardColSize - 1)
                sum += board[i][j + 1];
            if(i > 0) {
                sum += board[i - 1][j];
                if(j > 0)
                    sum += board[i - 1][j - 1];
                if(j < boardColSize - 1)
                    sum += board[i - 1][j + 1];
            }
            if(i < boardRowSize - 1) {
                sum += board[i + 1][j];
                if(j > 0)
                    sum += board[i + 1][j - 1];
                if(j < boardColSize - 1)
                    sum += board[i + 1][j + 1];
            }*/
            switch (sum) {
            case 3:
                buffer[i % 2][j] = 1;
                break;
            case 4:
                buffer[i % 2][j] = board[i][j];
                break;
            default:
                buffer[i % 2][j] = 0;
                break;
            }
        }
    }
    if(boardRowSize == 1) {
        for(int k = 0; k < boardColSize; k++)
            board[0][k] = buffer[0][k];
    }
    if(boardRowSize >= 2) {
        for(int k = 0; k < boardColSize; k++) {
            board[boardRowSize - 2][k] = buffer[boardRowSize % 2][k];
            board[boardRowSize - 1][k] = buffer[(boardRowSize - 1) % 2][k];
        }
    }
}

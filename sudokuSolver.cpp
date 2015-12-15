class Solution {
public:
    bool slove = false;
    int row[9][9] = {{0}}, col[9][9] = {{0}}, box[9][9] = {{0}};
    void backtrack(vector<vector<char>>& board, int r, int c) {
        if(r == 9) {
            slove = true;
            return;
        }
        if(board[r][c] != '.')
            backtrack(board, r + (c == 8 ? 1 : 0), (c + 1) % 9);
        else {
            for(int i = 0; i < 9; i++) {
                if(row[r][i] == 0 && col[c][i] == 0 && box[r / 3 * 3 + c / 3][i] == 0) {
                    board[r][c] = i + '1';
                    row[r][i] = col[c][i] = box[r / 3 * 3 + c / 3][i] = 1;
                    backtrack(board, r + (c == 8 ? 1 : 0), (c + 1) % 9);
                    if(slove)
                        break;
                    board[r][c] = '.';
                    row[r][i] = col[c][i] = box[r / 3 * 3 + c / 3][i] = 0;
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int n = board[i][j] - '1';
                    row[i][n] = col[j][n] = box[i / 3 * 3 + j / 3][n] = 1;
                }
            }
        }
        backtrack(board, 0, 0);
    }
};

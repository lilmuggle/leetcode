class Solution {
public:
    vector<int> a{-1, 0, 0, 1}, b{0, -1, 1, 0};
    void bfs(vector<vector<char>> &board, int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        board[x][y] = 'Y';
        while(!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                if(tmp.first + a[i] >= 0 && tmp.first + a[i] < board.size() && tmp.second + b[i] >= 0 && tmp.second + b[i] < board[0].size()) {
                    if(board[tmp.first + a[i]][tmp.second + b[i]] == 'O') {
                        q.push(make_pair(tmp.first + a[i], tmp.second + b[i]));
                        board[tmp.first + a[i]][tmp.second + b[i]] = 'Y';
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() < 2 || board[0].size() < 2)
            return;
        for(int i = 0; i < board.size(); i += board.size() - 1) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O')
                    bfs(board, i, j);
            }
        }
        for(int j = 0; j < board[0].size(); j += board[0].size() - 1) {
            for(int i = 0; i < board.size(); i++) {
                if(board[i][j] == 'O')
                    bfs(board, i, j);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
};

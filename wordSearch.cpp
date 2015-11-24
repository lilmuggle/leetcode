class Solution {
public:
    vector<int> ii = {-1, 0, 0, 1};
    vector<int> jj = {0, -1, 1, 0};
    bool backtrack(vector<vector<char>>& b, int r, int c, string s, int n) {
        if(n == s.size())
            return true;
        for(int k = 0; k < 4; k++)
            if(r+ii[k]>=0&&r+ii[k]<b.size()&&c+jj[k]>=0&&c+jj[k]<b[0].size())
                if(b[r + ii[k]][c + jj[k]] == s[n]) {
                    b[r + ii[k]][c + jj[k]] = '#';
                    if(backtrack(b, r + ii[k], c + jj[k], s, n + 1))
                        return true;
                    b[r + ii[k]][c + jj[k]] = s[n];
                }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0||board.size()==0||word.size()>board.size()*board[0].size())
            return false;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if(backtrack(board, i, j, word, 1))
                        return true;
                    board[i][j] = word[0];
                }
        return false;
    }
};

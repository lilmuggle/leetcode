class TrieNode {
public:
    TrieNode* childNodes[26];
    bool isWord;
    TrieNode() {
        memset(childNodes, 0, sizeof(childNodes));
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            if(tmp->childNodes[word[i] - 'a'] == NULL)
                tmp->childNodes[word[i] - 'a'] = new TrieNode();
            tmp = tmp->childNodes[word[i] - 'a'];
        }
        tmp->isWord = true;
    }
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->isWord;
    }
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
private:
    TrieNode* root;
    TrieNode* find(string key) {
        TrieNode* tmp = root;
        for(int i = 0; tmp && i < key.size(); i++)
            tmp = tmp->childNodes[key[i] - 'a'];
        return tmp;
    }
};

class Solution {
public:
    Trie trie;
    set<string> res;
    vector<int> ii = {-1, 0, 0, 1};
    vector<int> jj = {0, -1, 1, 0};
    void backtrack(vector<vector<char>>& b, int r, int c, string s) {
        if(b[r][c] == '#')
            return;
        s += b[r][c];
        char tmp = b[r][c];
        b[r][c] = '#';
        if(trie.search(s))
            res.insert(s);
        if(trie.startsWith(s))
            for(int k = 0; k < 4; k++)
                if(r+ii[k]>=0&&r+ii[k]<b.size()&&c+jj[k]>=0&&c+jj[k]<b[0].size())
                    backtrack(b, r + ii[k], c + jj[k], s);
        b[r][c] = tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string w : words)
            trie.insert(w);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                backtrack(board, i, j, "");
        return vector<string>(res.begin(), res.end());
    }
};

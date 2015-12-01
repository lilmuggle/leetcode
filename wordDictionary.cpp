class TrieNode {
public:
    TrieNode* childNodes[26];
    bool isWord;
    TrieNode() {
        memset(childNodes, 0, sizeof(childNodes));
        isWord = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            if(tmp->childNodes[word[i] - 'a'] == NULL)
                tmp->childNodes[word[i] - 'a'] = new TrieNode();
            tmp = tmp->childNodes[word[i] - 'a'];
        }
        tmp->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root, word);
    }
private:
    TrieNode* root;
    bool dfs(TrieNode* t, string word) {
        for(int i = 0; t && i < word.size(); i++) {
            if(word[i] == '.') {
                for(int j = 0; j < 26; j++) {
                    if(dfs(t->childNodes[j], word.substr(i + 1)))
                        return true;
                }
                return false;
            }
            else
                t = t->childNodes[word[i] - 'a'];
        }
        return t != NULL && t->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

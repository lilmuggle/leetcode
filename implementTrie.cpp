class TrieNode {
public:
    // Initialize your data structure here.
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

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            if(tmp->childNodes[word[i] - 'a'] == NULL)
                tmp->childNodes[word[i] - 'a'] = new TrieNode();
            tmp = tmp->childNodes[word[i] - 'a'];
        }
        tmp->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:
    TrieNode* root;
    TrieNode* find(string key) {
        TrieNode* tmp = root;
        for(int i = 0; tmp && i < key.size(); i++) {
            tmp = tmp->childNodes[key[i] - 'a'];
        }
        return tmp;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

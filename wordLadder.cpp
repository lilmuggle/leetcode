//BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int t = 1;
        queue<string> word;
        wordList.insert(endWord);
        word.push(beginWord);
        while(!word.empty()) {
            int num = word.size();
            for(int i = 0; i < num; i++) {
                string w = word.front();
                word.pop();
                wordList.erase(w);
                if(w == endWord)
                    return t;
                for(int j = 0; j < w.size(); j++) {
                    //char letter = w[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        w[j] = c;
                        if(wordList.find(w) != wordList.end()) {
                            word.push(w);
                            wordList.erase(w);
                        }
                    }
                    //w[j] = letter;
                }
            }
            t++;
        }
        return 0;
    }
};
